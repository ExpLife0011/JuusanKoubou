diff --git a/FileIO.bak b/FileIO.cpp
index eab40df..f10f425 100644
--- a/FileIO.bak
+++ b/FileIO.cpp
@@ -6,6 +6,8 @@
 #pragma comment(linker, "/ENTRY:main")
 
 #include <stdio.h>
+#include <ctype.h>
+#include <conio.h>
 #define TRUE 1
 #define FALSE 0
 
@@ -270,6 +272,7 @@ void popen()
         (ActiveEntryPtr2->pcode)[k]=(entryPtr1->pcode)[k];
     ActiveEntryPtr2->rpointer=0;
     ActiveEntryPtr2->wpointer=0;
+    ActiveEntryPtr2->addr = 0;
     printf("�ļ��򿪳ɹ���\n");
 }
 
@@ -385,12 +388,33 @@ void pdelete()
 //--------------------------------------------------------------------------
 void pread()
 {
+    FILE *fp;
+    dataActive *p;
+
+    printf("ȷʵҪ��test.txt���뵽�ĸ��ļ�: ");
+    fgets(name, sizeof(name), stdin);
+    
+    p = entryBeginPtr;
+    while (p->next)
+    {
+        if (strncmp(p->filename, name, sizeof(name)) == 0)
+            break;
+    }
+    if (p->next == NULL)
+    {
+        printf("�Ҳ��� %s.\n", name);
+        return;
+    }
+
+    fp = fopen("test.txt", "rb");
+    p->
 }
 
 
 //--------------------------------------------------------------------------
 void pwrite()
 {
+    printf("current opened file: %s\n", name);
 }
 
 
 
 ûд��...
