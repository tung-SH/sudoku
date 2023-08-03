/*******************************************
 * linked_list.c -- định nghĩa cho cấu trúc 
 *      dữ liệu danh sách liên kết 
 * 
 * PURPOSE: 
 *      - tổng quan: Học cấu trúc dữ liệu, 
 *          tạo ra abstract data types  
 *      - cụ thể: 
 *          1. Định nghĩa DS
 *          2. Tạo hàm thêm, xóa, tìm 
 * 
 * STATUS: 
 *      - [x]: code chưa hoàn thiện 
 *      - [ ]: code hoàn thành mục đích 
 *      - [ ]: code gặp lỗi tại dòng 
 *              Ghi chú lỗi      
 * 
 * SOURCE: Sách practical C 
 * 
 * NOTE: linked list giống như cái hộp có đáy
 *      bỏ thùng vào hộp thì sau đó lấy cái ở 
 *      trên ra trước rồi mới lấy được cái ở 
 *      đáy 
**********************************************/
#include "setting_general.h"
#include <stdlib.h>
#include <stdio.h>


struct linked_list {
    struct linked_list *next_node_ptr; /* pointer to next node */ 
    int value; /* value of this node */
}; 

typedef struct linked_list linked_list; 

/****************************************
 * linked_list_print -- in ra danh sách 
 *      liên kết 
 * 
 * parameter
 *      linked_list_ptr -- con trỏ chứa
 *          giá trị danh sách liên kết 
 * 
 * return 
 *      none 
 * 
*/
void linked_list_print(linked_list *linked_list_ptr) {
    linked_list *curr_node_ptr; /* biến chứa biến phần tử hiện tại của danh sách */
    curr_node_ptr = linked_list_ptr; /* */

    printf("Linked list:\n"); 
    while (1) {
        if (curr_node_ptr == NULL) { /* chả có biến nào cả */
            printf("End of linked list.\n"); 
            break; 
        } 
        printf("Value: %d.\n", (*curr_node_ptr).value); /* in ra giá trị của biến phần tử hiện tại */
        
        curr_node_ptr = (*curr_node_ptr).next_node_ptr; /* chuyển sang phần tử tiếp theo trong danh sách */
    }
}



/*******************************************
 * linked_list_add -- thêm phần tử vào cấu
 *      trúc dữ liệu danh sách liên kết 
 *      (linked list)
 * 
 * parameter
 *      linked_list_ptr -- con trỏ trỏ tới
 *          biến đầu tiên của danh sách 
 * 
 *      valueV -- giá trị số nguyên của phần tử 
 *          được thêm vào danh sách liên kết 
 * 
 * return
 *      none 
 * 
*/
void linked_list_add(linked_list **linked_list_ptr, int valueV) {
    linked_list *new_node_ptr; /* con trỏ chứa địa chỉ của biến tiếp của danh sách liên kết */
    new_node_ptr = (linked_list*)malloc(sizeof(linked_list)); /* chừa chỗ bộ nhớ đủ chứa 1 biến phần tử của danh sách và trả về địa chỉ của vùng nhớ tới biến đó */

    (*new_node_ptr).value = valueV; /* gán giá trị của phần tử mới */
    (*new_node_ptr).next_node_ptr = *linked_list_ptr; /* cho phần tử đó lên đầu danh sách */

    *linked_list_ptr = new_node_ptr; /* danh sách đại diện bỏi con trỏ chứa biến của phần tử đứng đầu danh sách vừa tạo */
}


#ifdef DEBUG_G

linked_list *treasure = NULL; /* pointers to first node of linked list */
/* ko chứa biến nào cả == linked_list trống */

int main(void) {
    linked_list_add(&treasure, 4); 
    linked_list_add(&treasure, 6); 

    linked_list_print(treasure); 
}

#endif