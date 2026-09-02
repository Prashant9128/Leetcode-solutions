public class Add_Two_Numbers {

	public class Solution {
	    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
	        if (l1 == null || l2 == null) {
	            return l1 == null ? l2 : l1;
	        }

	        // boolean style, 0 or 1
	        int carry = 0;

	        ListNode dummy = new ListNode(0);
	        ListNode dummyCopy = dummy;

	        while (l1 != null || l2 != null) {
	            int sum = (l1 == null ? 0 : l1.val) + (l2 == null ? 0 : l2.val) + carry;

	            // append to result list
	            dummy.next = new ListNode(sum % 10);
	            carry = sum >= 10 ? 1 : 0;

	            // move to next node
	            l1 = l1 == null ? null : l1.next;
	            l2 = l2 == null ? null : l2.next;
	            dummy = dummy.next;
	        }

	        // @note: I missed final check
	        if (carry == 1) {
	            dummy.next = new ListNode(carry);
	        }

	        return dummyCopy.next;
	    }
	}

}



/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        int carry = 0;
        ListNode cur = dummy;
        while (l1 != null || l2 != null || carry != 0) {
            int s = (l1 == null ? 0 : l1.val) + (l2 == null ? 0 : l2.val) + carry;
            carry = s / 10;
            cur.next = new ListNode(s % 10);
            cur = cur.next;
            l1 = l1 == null ? null : l1.next;
            l2 = l2 == null ? null : l2.next;
        }
        return dummy.next;
    }
}