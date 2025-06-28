#include <stdio.h>
#include <stdlib.h>

// تعريف هيكل العقدة
struct Node {
    int data;           // البيانات المخزنة في العقدة
    struct Node* next;  // مؤشر للعقدة التالية
};

// دالة لإنشاء عقدة جديدة
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("خطأ في تخصيص الذاكرة!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// دالة لإضافة عقدة في بداية القائمة
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// دالة لإضافة عقدة في نهاية القائمة
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    
    // إذا كانت القائمة فارغة
    if (head == NULL) {
        return newNode;
    }
    
    // الانتقال إلى آخر عقدة
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// دالة لحذف عقدة من القائمة
struct Node* deleteNode(struct Node* head, int data) {
    if (head == NULL) {
        return NULL;
    }
    
    // إذا كانت العقدة المراد حذفها هي العقدة الأولى
    if (head->data == data) {
        struct Node* temp = head->next;
        free(head);
        return temp;
    }
    
    // البحث عن العقدة المراد حذفها
    struct Node* current = head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }
    
    // إذا وجدت العقدة
    if (current->next != NULL) {
        struct Node* temp = current->next;
        current->next = temp->next;
        free(temp);
    }
    
    return head;
}

// دالة لعرض القائمة
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// دالة لتحرير الذاكرة
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

// دالة رئيسية لتجربة الوظائف
int main() {
    struct Node* head = NULL;
    
    // إضافة عناصر للقائمة
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtBeginning(head, 5);
    
    printf("القائمة الأصلية:\n");
    displayList(head);
    
    // حذف عنصر
    head = deleteNode(head, 20);
    printf("\nالقائمة بعد حذف 20:\n");
    displayList(head);
    
    // تحرير الذاكرة
    freeList(head);
    
    return 0;
} 