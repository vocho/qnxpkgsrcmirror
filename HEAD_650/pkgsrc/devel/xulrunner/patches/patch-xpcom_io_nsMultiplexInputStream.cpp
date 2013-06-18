$NetBSD$

--- xpcom/io/nsMultiplexInputStream.cpp.orig	2013-04-10 03:03:01.000000000 +0000
+++ xpcom/io/nsMultiplexInputStream.cpp
@@ -511,7 +511,7 @@ nsMultiplexInputStream::Seek(int32_t aWh
             }
 
             // See if we have enough data in the current stream.
-            if (std::abs(remaining) < streamPos) {
+            if (llabs(remaining) < streamPos) {
                 rv = stream->Seek(NS_SEEK_END, remaining);
                 NS_ENSURE_SUCCESS(rv, rv);
 
@@ -519,7 +519,7 @@ nsMultiplexInputStream::Seek(int32_t aWh
                 mStartedReadingCurrent = true;
 
                 remaining = 0;
-            } else if (std::abs(remaining) > streamPos) {
+            } else if (llabs(remaining) > streamPos) {
                 if (i > oldCurrentStream ||
                     (i == oldCurrentStream && !oldStartedReadingCurrent)) {
                     // We're already at start so no need to seek this stream
@@ -529,7 +529,7 @@ nsMultiplexInputStream::Seek(int32_t aWh
                     rv = stream->Tell(&avail);
                     NS_ENSURE_SUCCESS(rv, rv);
 
-                    int64_t newPos = streamPos + NS_MIN(avail, std::abs(remaining));
+                    int64_t newPos = streamPos + NS_MIN(avail, llabs(remaining));
 
                     rv = stream->Seek(NS_SEEK_END, -newPos);
                     NS_ENSURE_SUCCESS(rv, rv);
