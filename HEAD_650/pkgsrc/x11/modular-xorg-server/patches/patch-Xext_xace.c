$NetBSD$

--- Xext/xace.c.orig	2009-10-12 02:52:40.000000000 +0000
+++ Xext/xace.c
@@ -82,9 +82,21 @@ void XaceHookAuditEnd(ClientPtr ptr, int
  */
 int XaceHook(int hook, ...)
 {
-    pointer calldata;	/* data passed to callback */
+    union {
+        XaceResourceAccessRec res;
+        XaceDeviceAccessRec dev;
+        XaceSendAccessRec send;
+        XaceReceiveAccessRec recv;
+        XaceClientAccessRec client;
+        XaceExtAccessRec ext;
+        XaceServerAccessRec server;
+        XaceScreenAccessRec screen;
+        XaceAuthAvailRec auth;
+        XaceKeyAvailRec key;
+    } u;
     int *prv = NULL;	/* points to return value from callback */
     va_list ap;		/* argument list */
+
     va_start(ap, hook);
 
     /* Marshal arguments for passing to callback.
@@ -92,129 +104,99 @@ int XaceHook(int hook, ...)
      * the arguments and integer return parameter, or in some cases just
      * sets calldata directly to a single argument (with no return result)
      */
-    switch (hook)
-    {
-	case XACE_RESOURCE_ACCESS: {
-	    XaceResourceAccessRec rec = {
-		va_arg(ap, ClientPtr),
-		va_arg(ap, XID),
-		va_arg(ap, RESTYPE),
-		va_arg(ap, pointer),
-		va_arg(ap, RESTYPE),
-		va_arg(ap, pointer),
-		va_arg(ap, Mask),
-		Success /* default allow */
-	    };
-	    calldata = &rec;
-	    prv = &rec.status;
-	    break;
-	}
-	case XACE_DEVICE_ACCESS: {
-	    XaceDeviceAccessRec rec = {
-		va_arg(ap, ClientPtr),
-		va_arg(ap, DeviceIntPtr),
-		va_arg(ap, Mask),
-		Success /* default allow */
-	    };
-	    calldata = &rec;
-	    prv = &rec.status;
-	    break;
-	}
-	case XACE_SEND_ACCESS: {
-	    XaceSendAccessRec rec = {
-		va_arg(ap, ClientPtr),
-		va_arg(ap, DeviceIntPtr),
-		va_arg(ap, WindowPtr),
-		va_arg(ap, xEventPtr),
-		va_arg(ap, int),
-		Success /* default allow */
-	    };
-	    calldata = &rec;
-	    prv = &rec.status;
-	    break;
-	}
-	case XACE_RECEIVE_ACCESS: {
-	    XaceReceiveAccessRec rec = {
-		va_arg(ap, ClientPtr),
-		va_arg(ap, WindowPtr),
-		va_arg(ap, xEventPtr),
-		va_arg(ap, int),
-		Success /* default allow */
-	    };
-	    calldata = &rec;
-	    prv = &rec.status;
-	    break;
-	}
-	case XACE_CLIENT_ACCESS: {
-	    XaceClientAccessRec rec = {
-		va_arg(ap, ClientPtr),
-		va_arg(ap, ClientPtr),
-		va_arg(ap, Mask),
-		Success /* default allow */
-	    };
-	    calldata = &rec;
-	    prv = &rec.status;
-	    break;
-	}
-	case XACE_EXT_ACCESS: {
-	    XaceExtAccessRec rec = {
-		va_arg(ap, ClientPtr),
-		va_arg(ap, ExtensionEntry*),
-		DixGetAttrAccess,
-		Success /* default allow */
-	    };
-	    calldata = &rec;
-	    prv = &rec.status;
-	    break;
-	}
-	case XACE_SERVER_ACCESS: {
-	    XaceServerAccessRec rec = {
-		va_arg(ap, ClientPtr),
-		va_arg(ap, Mask),
-		Success /* default allow */
-	    };
-	    calldata = &rec;
-	    prv = &rec.status;
-	    break;
-	}
-	case XACE_SCREEN_ACCESS:
-	case XACE_SCREENSAVER_ACCESS: {
-	    XaceScreenAccessRec rec = {
-		va_arg(ap, ClientPtr),
-		va_arg(ap, ScreenPtr),
-		va_arg(ap, Mask),
-		Success /* default allow */
-	    };
-	    calldata = &rec;
-	    prv = &rec.status;
-	    break;
-	}
-	case XACE_AUTH_AVAIL: {
-	    XaceAuthAvailRec rec = {
-		va_arg(ap, ClientPtr),
-		va_arg(ap, XID)
-	    };
-	    calldata = &rec;
-	    break;
-	}
-	case XACE_KEY_AVAIL: {
-	    XaceKeyAvailRec rec = {
-		va_arg(ap, xEventPtr),
-		va_arg(ap, DeviceIntPtr),
-		va_arg(ap, int)
-	    };
-	    calldata = &rec;
-	    break;
-	}
-	default: {
-	    va_end(ap);
-	    return 0;	/* unimplemented hook number */
-	}
+    switch (hook) {
+    case XACE_RESOURCE_ACCESS:
+        u.res.client = va_arg(ap, ClientPtr);
+        u.res.id = va_arg(ap, XID);
+        u.res.rtype = va_arg(ap, RESTYPE);
+        u.res.res = va_arg(ap, pointer);
+        u.res.ptype = va_arg(ap, RESTYPE);
+        u.res.parent = va_arg(ap, pointer);
+        u.res.access_mode = va_arg(ap, Mask);
+
+        u.res.status = Success; /* default allow */
+        prv = &u.res.status;
+        break;
+    case XACE_DEVICE_ACCESS:
+        u.dev.client = va_arg(ap, ClientPtr);
+        u.dev.dev = va_arg(ap, DeviceIntPtr);
+        u.dev.access_mode = va_arg(ap, Mask);
+
+        u.dev.status = Success; /* default allow */
+        prv = &u.dev.status;
+        break;
+    case XACE_SEND_ACCESS:
+        u.send.client = va_arg(ap, ClientPtr);
+        u.send.dev = va_arg(ap, DeviceIntPtr);
+        u.send.pWin = va_arg(ap, WindowPtr);
+
+        u.send.events = va_arg(ap, xEventPtr);
+        u.send.count = va_arg(ap, int);
+
+        u.send.status = Success;        /* default allow */
+        prv = &u.send.status;
+        break;
+    case XACE_RECEIVE_ACCESS:
+        u.recv.client = va_arg(ap, ClientPtr);
+        u.recv.pWin = va_arg(ap, WindowPtr);
+
+        u.recv.events = va_arg(ap, xEventPtr);
+        u.recv.count = va_arg(ap, int);
+
+        u.recv.status = Success;        /* default allow */
+        prv = &u.recv.status;
+        break;
+    case XACE_CLIENT_ACCESS:
+        u.client.client = va_arg(ap, ClientPtr);
+        u.client.target = va_arg(ap, ClientPtr);
+        u.client.access_mode = va_arg(ap, Mask);
+
+        u.client.status = Success;      /* default allow */
+        prv = &u.client.status;
+        break;
+    case XACE_EXT_ACCESS:
+        u.ext.client = va_arg(ap, ClientPtr);
+
+        u.ext.ext = va_arg(ap, ExtensionEntry *);
+        u.ext.access_mode = DixGetAttrAccess;
+        u.ext.status = Success; /* default allow */
+        prv = &u.ext.status;
+        break;
+    case XACE_SERVER_ACCESS:
+        u.server.client = va_arg(ap, ClientPtr);
+        u.server.access_mode = va_arg(ap, Mask);
+
+        u.server.status = Success;      /* default allow */
+        prv = &u.server.status;
+        break;
+    case XACE_SCREEN_ACCESS:
+    case XACE_SCREENSAVER_ACCESS:
+        u.screen.client = va_arg(ap, ClientPtr);
+        u.screen.screen = va_arg(ap, ScreenPtr);
+        u.screen.access_mode = va_arg(ap, Mask);
+
+        u.screen.status = Success;      /* default allow */
+        prv = &u.screen.status;
+        break;
+    case XACE_AUTH_AVAIL:
+        u.auth.client = va_arg(ap, ClientPtr);
+        u.auth.authId = va_arg(ap, XID);
+
+        break;
+    case XACE_KEY_AVAIL:
+        u.key.event = va_arg(ap, xEventPtr);
+        u.key.keybd = va_arg(ap, DeviceIntPtr);
+        u.key.count = va_arg(ap, int);
+
+        break;
+    default:
+        va_end(ap);
+        return 0;               /* unimplemented hook number */
     }
     va_end(ap);
  
     /* call callbacks and return result, if any. */
-    CallCallbacks(&XaceHooks[hook], calldata);
+    CallCallbacks(&XaceHooks[hook], &u);
     return prv ? *prv : Success;
 }
 
