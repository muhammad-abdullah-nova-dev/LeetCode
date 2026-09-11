use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    pub fn average_of_subtree(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut ans = 0;

        fn dfs(node: &Option<Rc<RefCell<TreeNode>>>, ans: &mut i32) -> (i32, i32) {
            match node {
                None => (0, 0),
                Some(n) => {
                    let n = n.borrow();
                    let (ls, lc) = dfs(&n.left, ans);
                    let (rs, rc) = dfs(&n.right, ans);
                    let sum = ls + rs + n.val;
                    let cnt = lc + rc + 1;
                    if sum / cnt == n.val {
                        *ans += 1;
                    }
                    (sum, cnt)
                }
            }
        }

        dfs(&root, &mut ans);
        ans
    }
}