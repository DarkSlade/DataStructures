
#include <stdio.h>
#include <stdlib.h>
#include "hamming_numbers.h"

int can_stop(dl_list *final, dl_list *temp, int n);

dl_list *generate_terms(dl_list *list, int multiplier);

dl_list *generate_hamming_numbers(int n) 
{
  dl_list *final = create_dl_list();
  dl_list *temp = create_dl_list();
  dl_list *l2 = NULL;
  dl_list *l3 = NULL;
  dl_list *l5 = NULL;

  add_node(final,1);
  add_node(temp,2);
  add_node(temp,3);
  add_node(temp,5);

  while(!can_stop(final,temp,n))
  {
    dl_list *copy_list = final;
    final = merge_lists(final,temp);
    free_list(copy_list);
    l2 = generate_terms(temp,2);
    l3 = generate_terms(temp,3);
    l5 = generate_terms(temp,5);

    free_list(temp);
    temp = merge_lists(l2,l3);
    copy_list = temp;
    temp = merge_lists(temp,l5);
    free_list(copy_list);
    copy_list = NULL;

    free_list(l2);
    free_list(l3);
    free_list(l5);
    l2 = NULL;
    l3 = NULL;
    l5 = NULL;
  }

  free_list(temp);
  temp = NULL:

  dl_list *copy_list = final;
  final = range_list(final, 0, n);

  free_list(copy_list);
  copy_list = NULL:

  return final;
}

int can_stop(dl_list *final, dl_list *temp, int n)
{
  rewind_list(temp);
  int min = temp->current->data;

  return final->length >= n
    && get_list_node(final,n-1)->data <= min;
}

dl_list *generate_terms(dl_list *list, int multiplier)
{
  dl_list *term_list = create_dl_list();
  rewind_list(list);
  while(list->current)
  {
    add_node(term_list, list->current->data * multiplier);
    increment_list(list);
  }
  return term_list;
}

