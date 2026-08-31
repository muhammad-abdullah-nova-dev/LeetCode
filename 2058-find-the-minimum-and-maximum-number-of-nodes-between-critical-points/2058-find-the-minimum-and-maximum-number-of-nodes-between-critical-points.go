/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func nodesBetweenCriticalPoints(head *ListNode) []int {
    pre := head
    cur := head.Next
    ans := []int{-1, -1}
    prePosition, curPosition, firstPosition, position := -1, -1, -1, 0
    
    for cur.Next != nil {
        if (cur.Val < pre.Val && cur.Val < cur.Next.Val) || (cur.Val > pre.Val && cur.Val > cur.Next.Val) {
            // local
            prePosition = curPosition
            curPosition = position
            
            if firstPosition == -1 {
                firstPosition = position
            }
            if prePosition != -1 {
                if ans[0] == -1 {
                    ans[0] = curPosition - prePosition
                } else {
                    if curPosition-prePosition < ans[0] {
                        ans[0] = curPosition - prePosition
                    }
                }
                ans[1] = position - firstPosition
            }
        }
        position++
        pre = cur
        cur = cur.Next
    }
    return ans
}