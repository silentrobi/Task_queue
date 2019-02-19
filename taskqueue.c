//
// Created by MOHAMMAD ABU MUSA RABIUL on 28-Oct-18.
// ID:  220201072
//

#include "taskqueue.h"
#include <time.h>

/* global head variables */
ListNode* listHead= NULL;
TaskNode* taskHead= NULL;

/*List node functions */

//Create and return a node with the given data
ListNode* createNode(int value){
    ListNode *newNode = malloc(sizeof(ListNode));
    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

//checks if there is an element in the list or not
int isEmpty(ListNode *head){
    ListNode* temp = head;
    if (temp == NULL) return 1;
    return 0;

}

/* Inserts a new node on the front of the list. */

int insert(int value){

    ListNode** head= &listHead; // assigning global head value of List
    if (!search(value)) { // if the value is not present in the list
        ListNode* newNode = createNode(value);
        sortedInsertion(head,newNode);
        return 1;
    }
    return 0; // if present return false

}

//Delete first ListNode where given data occurs
int  delete( int value) // return the value which is deleted.
{
    ListNode ** head= &listHead; // assigning global head value of List
    ListNode* temp = *head, *prev= NULL; //Store head node

    // if list is empty
    if (*head == NULL) return 0; // 0 means couldn't find the value in the list to be deleted

    // If head node holds the date to be deleted
    if (temp != NULL && temp->data == value)
    {

        *head = temp->next;   // Changed head
        free(temp);   // free head
        return 1;
    }

    // Look for the  value to be deleted,
    //Also keep track of the  previous node because we have to change the 'prev->next'
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    // If next node is empty
    if (temp == NULL) return 0; // 0 means couldn't find the value in the list to be deleted


    // Unlink the node from linked list if value of the node is found in the node list
    prev->next = temp->next;

    free(temp);  // Free memory
    return 1;
}

int search(int value){ // sequential search
    ListNode* temp = listHead; // assigning global head value of Node List
    while (!isEmpty(temp)){ // if not empty
        if (temp->data == value)
        {
            return 1; // return true

        }
        temp = temp->next;


    }

    return 0; // return false


}



//print the values of each node in the list
void printList(ListNode *head){
    ListNode* temp = head;
    if (temp == NULL){
        printf("%s\n", "LIST IS EMPTY");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp=temp->next;
    }
}


/* function to insert a newNode in a list. Note that this
function expects a pointer to pointer to  head as it can modify the
head of the input linked list*/
void sortedInsertion(ListNode** head, ListNode* newNode) {

    /* special case for the head*/
    if (*head == NULL || (*head)->data > newNode->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        /* finding the node before insertion */
        ListNode *current = *head;
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}
void deleteAll(ListNode** head)
    {

        ListNode* current = *head;

        ListNode* next;
        if (isEmpty(*head)){

            printf("%s\n", "Can't delete empty list");
            return;
        }
        while (current != NULL)
        {
            next = current->next;
            free(current);
            current = next;
        }

       *head=NULL; //making head value null
        printf("\n%s", "De-allocated all elements in the list\n" );
    }

/* task functions*/	

void Task_queue(int n){
    srand((unsigned)time(NULL));

    int i= 0;
    ListNode* headNode= NULL;
    /* generating tasks and putting them into queue */
    if (n == 0){
        printf("%s\n", "No task queue is created.");
        return;
    }
    for(;i<n; i++) {
        int randomType = rand() % 3; // random type
        int randomValue= rand() % 100 ;  // taking random value [0-99] Note: random value can be chosen in any range
        Task_enqueue(i,randomType,randomValue); //en-queuing task one by one into the task queue
    }
    printf("Generated %d random list tasks...\n",n);





}

TaskNode * createTask(int task_num, int taskType, int value){ // create a task
    TaskNode *newTask = malloc(sizeof(TaskNode));
    newTask->value = value;
    newTask->task_num= task_num;
    newTask->task_type= taskType;
    newTask->next = NULL;

    return newTask;

}

void Task_enqueue(int task_num, int task_type, int value) {
    TaskNode ** head = &taskHead; //// assigning global head value of Task queue
    TaskNode *newTask = createTask(task_num, task_type, value);
    TaskNode *temp = *head;
    if (temp == NULL) { // task head is null
        *head = newTask;
        return;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newTask;
        return;
    }
}
void processTask(TaskNode* task){ // process a given Task

    int flag=0;

    if (task == NULL){
        printf("%s", "No Task to process");
        return;
    }
    else if (task->task_type == 0) { //insert: 0
        flag= insert(task->value);
        if (flag){
            printf("Task %d-insert %d: %d %s\n",task->task_num, task->value,task->value, "is inserted.");
        }
        else{
            printf("Task %d-insert %d: %d %s\n",task->task_num, task->value,task->value, "can not be inserted");
        }
    }
    else if (task->task_type == 1) {// delete: 1
        flag = delete(task->value);
        if (flag)  printf("Task %d-delete %d: %d %s\n",task->task_num, task->value,task->value, "is deleted.");
        else  printf("Task %d-delete %d: %d %s\n",task->task_num, task->value,task->value, "can not be deleted");
    }

    else if (task->task_type == 2) { //search: 2
        flag = search(task->value);
        if (flag) {
            printf("Task %d-search %d: %d %s\n",task->task_num, task->value,task->value, "is present.");
        }
        else printf("Task %d-search %d: %d %s\n",task->task_num, task->value,task->value, "is not found.");
    }else{
        printf("%s\n", "UNKNOWN ERROR OCCURRED");
    }



}

void manageTasks( int n){
    Task_queue(n);
    while(getTaskSize(taskHead) >0){
        Task_dequeue();


    }
    printf("%s\n","Final List:");
    printList(listHead); 
    deleteAll(&listHead); //deallocating all elements in the list



}


int Task_dequeue(){

    TaskNode* delete;
    if (taskHead == NULL){
        printf("%s", "No Task in the queue.");
        return 0;
    }
    else if (taskHead != NULL){
        delete= taskHead;

        taskHead = taskHead->next; // changing the head value.
        processTask(delete); // process the task before deleting.
        free(delete); // de-allocating the de-queued node.
        return 1;
    }
    else{
        printf("%s\n", "UNKNOWN ERROR OCCURRED DURING DE_QUEUE.");
    }


}

int getTaskSize(TaskNode *head){
    int count = 0;
    TaskNode* temp = head;
    while (temp != NULL) {
        count++;
        temp=temp->next;
    }
    return count;
}
