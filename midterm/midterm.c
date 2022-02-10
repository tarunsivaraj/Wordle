#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// PROBLEM 1

long long *fibonacci_numbers(int n) {
  // You're going to have to allocate an array, fill it in, and return it.
  // The array should be of length n.
  // Recall the first few entries should be 1, 1, 2, 3, 5, 8, ...
    long long *fib;
//    long long fibonacci_numbers[n];
//    fib = fibonacci_numbers;
    fib = (long long*)calloc (n ,sizeof(long long));
//    printf("%p\n", fib);

    if (n == 1) {
      long long x = 1;
      fib[0] = x;
//      printf("%lld", fib[0]);
      return fib;
//      printf("%lld\n", x);
    }
    long long previous1 = 1;
    long long previous2 = 0;
    long long current;
    
    long long x = 1;
    fib[0] = x;

//    printf("%lld\n", x);

    for (int i = 1; i < n; i++ ) {
        current = previous2 + previous1;
        previous2 = previous1;
        previous1 = current;
        fib[i] = current;
//        printf("%lld\n", current);
//        printf("%lld\n", fib[i]);
    }
//    printf("%lld\n", fib[1]);
    
    return fib;

}


// PROBLEM 2

typedef struct {
    int shoe_size;
    int customer_id;
    int num_purchases;
} ShoeCustomer;

void print_customer(ShoeCustomer* customer) {
    printf("Shoe size: %d, customer_id: %d, num_purchases: %d\n",customer->shoe_size, customer->customer_id, customer->num_purchases );
}

void bubble_sort_customers(ShoeCustomer* customers, int n_customers) {
  // Your code here! Make them sorted!
    ShoeCustomer temp;
    ShoeCustomer *customer1 = NULL;
    ShoeCustomer *customer2 = NULL;
    for (int x = 0; x < n_customers-1; x++) {
      for (int y = 0; y < n_customers-x-1; y++) {
        customer1 = (customers + y);
        customer2 = (customers + (y+1));
//        print_customer(customer1);
//        print_customer(customer2);
        if (customer1->shoe_size > customer2->shoe_size) {
          temp = *customer1;
          *customer1 = *customer2;
          *customer2 = temp;
        }
      }
    }
//    for (int x = 0; x < n_customers; x++) {
//      printf("%d\n", customers[x].shoe_size);
//        return customers
//    }
}

// PROBLEM 3

// A linked list of floating point numbers.
typedef struct LLfloat {
  float val;
  struct LLfloat *next;
} LLfloat;


float square(float x) {
    float sum;
    sum = x * x;
    return sum;
}


LLfloat *map_floats(float (*f)(float), LLfloat *numbers)  {
  // finish this function.
  // Should it be recursive? It's up to you, but it could be recursive!
  LLfloat* temp = numbers;
  LLfloat *prev = NULL;
  LLfloat *head = NULL;
  while(temp != NULL) {
    LLfloat* new = (LLfloat*)malloc(sizeof(LLfloat));
    
    new->next = NULL;
    new->val = f(temp->val);
//    printf("%f\n", new->val);
    if (prev != NULL) {
        prev->next = new;
        prev = new;
//        printf("Hi\n");
    }else {
        prev = new;
//        printf("hiii\n");
//        printf("%f\n", head->val);
    }
        
    if(head == NULL){
        head = new;
    }
//    printf("hi\n");
    temp = temp->next;
//    printf("hi");
  }
//  printf("%f\n", head->next->val);
  return head;
}

// PROBLEM 4

unsigned long dectobin(unsigned long x) {
  unsigned long binary = 0;
  int y = 1;
  int z = 1;

  while(x != 0) {
    y = x % 2;
    x = x / 2;
    binary = binary + y * z;
    z = z * 10;
  }
  return binary;
  
}

unsigned long compute_availability(unsigned long *calendars, int num_users) {

  for (int x = 0; x < num_users; x++) {
    calendars[0] = calendars[0] & calendars[x];
  }

  unsigned long availability = calendars[0];

  unsigned long conv = dectobin(calendars[0]);
  return conv;
}

// put examples for testing your functions in the main! You're going to have to
// figure out how to test these.
int main(void) {
  // question 1
    int n = 10;
    long long* f = fibonacci_numbers(n);
//    printf("%p\n", f);
    for (int x = 0; x < n; x++) {
        printf("%lld\n", f[x]);
    }
    
    /*
  // question 2
    int n_customers = 6;
    ShoeCustomer *customers = (ShoeCustomer* )calloc(n_customers, sizeof(ShoeCustomer));
    customers[0].shoe_size = 8;
    customers[0].customer_id = 1002;
    customers[0].num_purchases = 4;
    customers[1].shoe_size = 6;
    customers[1].customer_id = 1182;
    customers[1].num_purchases = 7;
    customers[2].shoe_size = 10;
    customers[2].customer_id = 1452;
    customers[2].num_purchases = 2;
    customers[3].shoe_size = 2;
    customers[3].customer_id = 1652;
    customers[3].num_purchases = 24;
    customers[4].shoe_size = 15;
    customers[4].customer_id = 1982;
    customers[4].num_purchases = 11;
    customers[5].shoe_size = 3;
    customers[5].customer_id = 1032;
    customers[5].num_purchases = 6;
   
    bubble_sort_customers(customers, n_customers);
   
    for (int x = 0; x < n_customers; x++) {
      printf("%d\n", customers[x].shoe_size);
    }

  // question 3
    LLfloat* one = (LLfloat*)malloc(sizeof(LLfloat));
    one->val = 10.0;
    one->next = NULL;
    LLfloat* two = (LLfloat*)malloc(sizeof(LLfloat));
    two->val = 20.0;
    two->next = one;
    LLfloat* three = (LLfloat*)malloc(sizeof(LLfloat));
    three->val = 30.0;
    three->next = two;
    LLfloat* four = (LLfloat*)malloc(sizeof(LLfloat));
    four->val = 40.0;
    four->next = three;
   
    LLfloat *head_val = map_floats(square, four);
   
   
//    printf("%f\n", head_val->val);
//    printf("%f\n", head_val->next->val);
    while(head_val != NULL){
        printf("%f\n", head_val->val);
        head_val = head_val->next;
//        printf("%f\n", head_val->val);
//        head_val = head_val->next;
//        printf("%f\n", head_val->val);
    }
    
    */
    //unsigned long arr[] = {0b001101, 0b001100, 0b001100};
    //printf("%lu\n", compute_availability(arr, 3));
    
    return 0;
}
