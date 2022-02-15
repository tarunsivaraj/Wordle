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

 Updated:

 For BFS, I will be basing it off the demo of BFS we did in class. First we need to initialize a start path variable to that you enqueue it since enqueue take a path argument. after that, 
 there will be a while loop which keeps running as long as there are places to visit. In that loop, you would check if i = j. Since you can't just put i == j, it would be
 current.vertices_visited[current.steps - 1] as i since it will get you the most recent vertice. The rest would be the same but you would need to put current.vertices_visited[current.steps - 1] this in
 the appropriate spot. It might be easier to make a variable. Then you would need to extend the path with the vertice you got and we are give a function path_extend for that reason.
 to_visit = enqueue_path(to_visit, path_extend(current, neighbor)); path_extend will return the extended path as a path type and enqueue takes a path type as a parameter. Now memory leaks would be an issue.
 I would write 2 extra functions to free the memory in the linked list, and another to fully dequeue everything frfom the queue, so that there is nothing left behind on the heap. 

 DFS would be very similar to BFS except we would need to use push and pop instead. For that I made a push and pop fucntion. The pop fucntion is just like the dequeue function, and the push fucntion will be a little different compared to the enqueue function. After making working push and pop functions. After that we would replace it with enqueue and dequeue and we have to change our for loop and our dfs should be working. I still don't know what the for loop would be but i will figure that out soon.

 We also need to as a graph destroy function, mentioned in the section slides. I should be similar to the one if hw3 excpet we are freeing the graph instead of a stack and we have to free each vertex by running it throught a for loop comparing it to the total number of vertices with (*g)->vertices.