# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class AddTwoNumbers:
    def addTwoNumbers(self, l1, l2):
        """
        Given two non-empty linked lists representing two non-negative integers, and the 
        digits being stored in reverse order with each of their nodes contain a single digit, 
        add the two numbers and return it as a linked list.
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = (l1.val + l2.val) // 10
        sumNode = head = ListNode((l1.val + l2.val) % 10)
        while l1.next is not None and l2.next is not None:
            sumNode.next = ListNode((l1.next.val + l2.next.val + carry) % 10)
            carry = (l1.next.val + l2.next.val + carry) // 10
            sumNode = sumNode.next
            l1, l2 = l1.next, l2.next
        if l1.next is not None:
            l1.next.val += carry
            carry = 0
            while l1.next is not None:
                sumNode.next = ListNode((l1.next.val + carry) % 10)
                carry = (l1.next.val + carry) // 10
                sumNode = sumNode.next
                l1 = l1.next
        if l2.next is not None:
            l2.next.val += carry
            carry = 0
            while l2.next is not None:
                sumNode.next = ListNode((l2.next.val + carry) % 10)
                carry = (l2.next.val + carry) // 10
                sumNode = sumNode.next
                l2 = l2.next
        if carry != 0:
            sumNode.next = ListNode(carry)
        return head

