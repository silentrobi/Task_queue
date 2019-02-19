//
// Created by MOHAMMAD ABU MUSA RABIUL on 28-Oct-18.
// ID:  220201072
//

#include<stdio.h>
#include<stdlib.h>

struct lst_node_s { // list node
    int data;
    struct lst_node_s *next;
};
struct tsk_node_s { // task node
    int task_num; //starting from 0
    int task_type; // insert:0, delete:1, search:2
    int value;
    struct tsk_node_s* next;
};

/* rename the type*/

typedef struct lst_node_s ListNode;
typedef struct tsk_node_s TaskNode;

/* List Node functions */

ListNode* createNode(int value); //Create and return a node with the given data
int isEmpty(ListNode *head); //checks if there is an element in the list or not
int insert(int value); //Add given node to the given index
int delete(int value); //Delete first ListNode where given data occurs
void printList(ListNode *head); //print the values of each node in the list
void sortedInsertion(ListNode** head, ListNode* newNode); //insert a node in sorted order
int search(int value); //search a value in the list
void deleteAll(ListNode** head); // delete all node list

/* Task queue functions */

void Task_queue(int n); //generate n random tasks for the task queue
void Task_enqueue(int task_num, int task_type, int value); //insert a new task into task queue
int Task_dequeue(); //take a task from task queue
void processTask(TaskNode * task); // process a task (insert/ search/ delete)
int getTaskSize(TaskNode *head); // get the size of the task
void manageTasks( int n); // manage all the tasks
