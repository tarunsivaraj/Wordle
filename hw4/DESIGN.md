So this assignment is using similar concepts ffrom last weeks lab but it is a little different.

There are 4 functions that we have to fill in. 

The first one is enqueue_path and this will be similar to what we worked on in class

 LLint *newnode = calloc(1, sizeof(LLint));
  newnode->val = val;

  if (q == NULL) {
    return newnode;
  }

  LLint *cur = q;
  while(cur->next != NULL) {
    cur = cur->next;
  }
  cur->next = newnode;
  return q;
}
 I will change this code to adapt to this assignment and the same goes for dequeue.

 For DFS and BFS, I am not too sure on how to solve this, but I will update the design doc with more information
 before the assignment due date.