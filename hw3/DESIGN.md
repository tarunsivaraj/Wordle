This assignment is about stacks and memory, like a learn how to do it assignment.

For stack_create, we are given the code for that so thhere is nothing we have to do for that.

for stack_push we would need to check the parameters firsts

first we have to check is the stack is null with this s == NULL. If that is true, return false. Or if there is nothing in the stack, then return false

After checking for that, we would add to the stack.

For stack_pop, it is just like the push function, except we pop the stack.

For empty, it would check for the first item, 

bool stack_empty(Stack *s) {
  if(s->top == 0) {
return true;
}
return false;

}

for delete,

void stack_delete(Stack **s) {
  if (*s && (*s)->items) {
free((*s)->items);
free(*s);
*s = NULL;
}
return;

}

This is what I had for another assignment for a similar function so I would change this up a little bit.

I'm not too sure how to so that last function, but I'll add it in after I attend a section