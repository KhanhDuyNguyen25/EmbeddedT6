#include <stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *makeNode(int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void duyet(node *head){
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    
}

int count(node *head){
    int dem = 0;
    while(head != NULL){
        dem++;
        head = head->next;
    }
    return dem;
}
// thêm 1 node vào đầu danh sách liên kết
void pushFront(node **head, int x){
    node *newNode = makeNode(x);
    newNode->next = *head; // địa chỉ của node head trong danh sách liên kết(*head toán tử giải tham chiếu)
    // bước2: cập nhật node head vào newNode
    *head = newNode;
}

// thêm 1 node vào cuối danh sách liên kết
void pushBack(node **head, int x){
    node *temp = *head;
    node *newNode = makeNode(x);
    if(*head== NULL){
        *head = newNode; return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    temp->next = newNode;
}

// Thêm 1 node vào giữa danh sách liên kết
void insert(node **head, int k,  int x){
    int n = _msize(*head);
    if(k < 1 || k > n+1){ return;}
    if(k == 1){pushFront(head, x);}
    node *temp = *head;
    for(int i = 1; i <= k - 2; i++){
        temp = temp -> next;
    }
    //temp = k - 1
    node *newNode = makeNode(x);
    newNode -> next = temp -> next;
    temp->next = newNode;
}

// Xóa node khỏi đầu Danh sách liên kết
void popFront(node **head){
    if(*head == NULL) return;
    node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Xóa node khỏi cuối Danh sách liên kết
void popBack(node **head){
    if(*head == NULL) return;
    node* temp = *head;
    if(temp->next == NULL){
        *head = NULL;
        free(temp);
        return;
    }
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    node *last = temp->next; // node cuoi
    temp->next =NULL;
    free(last);
}

// Xóa node ở giữa Danh sách liên kết
void erase(node **head, int k){
    int n = _msize(*head);
    if(k < 1 || k > n) return;
    if(k == 1) popFront(head);
    else{
        node *temp = *head;
        for(int i = 1; i <= k - 2; i++){
            temp = temp->next;
        }
        //temp: k -1
        node *kth = temp->next; //node thứ k
        temp->next = kth->next;
        free(kth);
    }
}

int main(){
    node *head = NULL;
    
    while(1){
        printf("\n.......................\n");
        printf("1. Them vao dau\n");
        printf("2. Them vao cuoi\n");
        printf("3. Them vao giua\n");
        printf("4. xoa node dau\n");
        printf("5. xoa node cuoi\n");
        printf("6. xoa node bat ki\n");
        printf("7. Duyet\n");
        printf(".......................\n");
        printf("Nhap lua chon :\n");
        int lc; scanf("%d", &lc);
        if(lc == 1){
            int x;
            printf("Nhap x: ");
            scanf("%d", &x);
            pushFront(&head, x);
        }
        else if(lc == 2){
            int x; printf("Nhap x: ");
            scanf("%d", &x);
            pushBack(&head, x);
        }
        else if(lc == 3){
            int x; printf("Nhap x: ");
            scanf("%d", &x);
            int k; printf("Nhap k: ");
            scanf("%d", &k);
            insert(&head, k, x);
        }
        else if(lc == 4){
            popFront(&head);
        }
        else if(lc == 5){
            popBack(&head);
        }
        else if(lc == 6){
            int k; 
            printf("Nhap vao vi tri can xoa: ");
            scanf("%d", &k);
            erase(&head, k);
        }
        else if(lc == 7){
            duyet(head);
        }else{
            break;
        }

    }

    return 0;
}