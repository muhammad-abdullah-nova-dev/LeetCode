class Solution(object):
    def nodesBetweenCriticalPoints(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: List[int]
        """
        first = -1
        last = -1
        idx = 1
        min_dist = float('inf')

        prev = head
        curr = head.next

        while curr.next is not None:
            if ((curr.val > prev.val and curr.val > curr.next.val) or
                (curr.val < prev.val and curr.val < curr.next.val)):

                if first == -1:
                    first = idx
                    last = idx
                else:
                    min_dist = min(min_dist, idx - last)
                    last = idx

            prev = curr
            curr = curr.next
            idx += 1

        if first == last:
            return [-1, -1]

        return [min_dist, last - first]