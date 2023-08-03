/*******************************************
 * ordered_linked_list.c -- tạo cấu trúc dữ 
 *      liệu danh sách liên kết có thứ tự 
 * 
 * PURPOSE: 
 *      - tổng quan: Học về cấu trúc dữ liệu
 *      - cụ thể: Định nghĩa phần tử, hàm 
 *          thêm, hàm in
 * 
 * STATUS: 
 *      - [x]: code chưa hoàn thiện 
 *      - [ ]: code hoàn thành mục đích 
 *      - [ ]: code gặp lỗi tại dòng 
 *              Ghi chú lỗi      
 * 
 * SOURCE: Sách Practical C
**********************************************/
#include "setting_general.h"
#include <stdlib.h>

struct linked_list {
    struct linked_list *next_ptr; /* pointer to next item */
    int value; /* value of item */
}; 

typedef struct linked_list linked_list; 

/*******************************************
 * order_linked_list_enter -- hàm thêm
 *      phần tử vào trong danh sách liên
 *      kết có thứ tự 
 * 
 * Parameters
 *      first_ptr_ptr -- vị trí chứa thông tin 
 *          vị trí kho báu đầu tiên
 *      value -- rương kho báu 
 * 
 * Return
 *      none 
 * 
*/
void ordered_linked_list_enter(linked_list **first_ptr_ptr, const int value) {
    linked_list *before_ptr; /* vị trí kho báu trước vị trí kho báu mới */
    linked_list *after_ptr; /* vị trí kho báu sau vị trí kho báu mới */
    linked_list *new_ptr; /* vị trí kho báu mới */

    /* tạo rương kho báu mới */
    new_ptr = (linked_list*)malloc(sizeof(linked_list)); 
    (*new_ptr).value = value; 

    if (*first_ptr_ptr == NULL) { /* nếu chưa có rương kho báu nào cả */
        new_ptr->next_ptr = *first_ptr_ptr; /* rương hiện tại sẽ là rương cuối của danh sách */
        *first_ptr_ptr = new_ptr; /* vị trí rương kho báu đầu tiên là vị trí rương hiện tại */
    } else if (new_ptr->value < (*first_ptr_ptr)->value) { /* nếu giá trị kho báu mới là bé nhất trong danh sách kho báu */
        new_ptr->next_ptr = *first_ptr_ptr; /* vị trí rương kho báu tiếp theo của rương mới là rương đầu tiên của danh sách cũ */
        *first_ptr_ptr = new_ptr; /* vị trí rương kho báu đầu tiên của danh sách kho báu là vị trí của rương kho báu mới */
    } else {
        /*************
         * khởi tạo 
        */
        before_ptr = *first_ptr_ptr; 
        after_ptr = before_ptr->next_ptr; 

        while (1) {
            if (after_ptr == NULL) { /* nếu hiện tại danh sách rương chỉ có 1 rương thôi và rương mới có giá trị lớn hơn rương duy nhất */
                before_ptr->next_ptr = new_ptr; 
                new_ptr->next_ptr = after_ptr;
                break; 
            } else if (before_ptr->value < new_ptr->value && new_ptr->value <= after_ptr->value) {
                before_ptr->next_ptr = new_ptr; 
                new_ptr->next_ptr = after_ptr;
                break; 
            } else {
                before_ptr = after_ptr; 
                after_ptr = after_ptr->next_ptr; 
            }
        }
    }
}


/****************************************
 * ordered_linked_list_print -- in ra 
 *      danh sách liên kết thứ tự 
 * 
 * Parameters
 *      first_ptr -- vị trí rương kho báu
 *          đầu tiên 
 * 
 * Return
 *      none 
 * 
*/
void ordered_linked_list_print(linked_list *first_ptr) {
    printf("Trò chơi săn tìm kho báu:\n"); 
    linked_list *curr_ptr; /* vị trị rương kho báu hiện tại */
    while (1) {
        if (curr_ptr == NULL) { /* nếu dò mà ra ko có rương thì nghỉ */
            printf("Ko còn rương kho báu nào cả.\n"); 
            break; 
        } else {
            printf("Giá trị rương: %d.\n", curr_ptr->value);   
            curr_ptr = curr_ptr->next_ptr; /* sang vị trí rương tiếp theo */
        }
    }
}


#ifdef DEBUG_G

linked_list *treasureHunt = NULL; /* trò chơi săn tìm kho báu nhưng mà chưa đặt kho báu 
vào vị trí nào cả */

int main(void) {
    ordered_linked_list_enter(&treasureHunt, 100);
    ordered_linked_list_enter(&treasureHunt, 750); 
    ordered_linked_list_enter(&treasureHunt, 370); 
    ordered_linked_list_enter(&treasureHunt, 1250); 
    ordered_linked_list_enter(&treasureHunt, 480); 
    ordered_linked_list_enter(&treasureHunt, 880);

    ordered_linked_list_print(treasureHunt);  


}



#endif