#include <iostream>
#include <math.h>
using namespace std;

int a[50000];

//Every TreeNode has a tree_node_score
struct tree_node_score{
    int left_joint_score;       //join as a left node, at least one element count
    int right_joint_score;      //join as a right node, at least one element count
    int total_score;            //total score of this node
    int best_score;             //best score of this node

    tree_node_score(){
        left_joint_score = 0;
        right_joint_score = 0;
        total_score = 0;
        best_score = 0;
    }
};

//TreeNode: Segement Tree
class TreeNode{
  private:
    TreeNode *left_node_;
    TreeNode *right_node_;
    int range_left_;
    int range_right_;
    tree_node_score node_score_;

  public:
    TreeNode(int range_left, int range_right){
        left_node_ = NULL;
        right_node_ = NULL;
        range_left_ = range_left;
        range_right_ = range_right;
        node_score_ = tree_node_score();
    }

    tree_node_score GetNodeScore(){
        return node_score_;
    }

    void BuildSegementTree(){
        //cout << "left = " << range_left_ << " right = " << range_right_ << endl;
        if (range_left_ == range_right_){
            node_score_.left_joint_score = a[range_left_];
            node_score_.right_joint_score = a[range_left_];
            node_score_.total_score = a[range_left_];
            node_score_.best_score = a[range_left_];
            return;
        }

        int range_middle = (range_left_ + range_right_) / 2;
        left_node_ = new TreeNode(range_left_, range_middle);
        left_node_->BuildSegementTree();
        tree_node_score left_node_score = left_node_->GetNodeScore();
        right_node_ = new TreeNode(range_middle + 1, range_right_);
        right_node_->BuildSegementTree();
        tree_node_score right_node_score = right_node_->GetNodeScore();

        node_score_.left_joint_score = max(left_node_score.left_joint_score, left_node_score.total_score + right_node_score.left_joint_score);
        node_score_.right_joint_score = max(right_node_score.right_joint_score, right_node_score.total_score + left_node_score.right_joint_score);
        node_score_.total_score = left_node_score.total_score + right_node_score.total_score;
        node_score_.best_score = max(max(max(max(node_score_.left_joint_score, node_score_.right_joint_score), left_node_score.best_score), right_node_score.best_score), left_node_score.right_joint_score + right_node_score.left_joint_score);
    }

    tree_node_score GetQueryScore(int x, int y){
        if ((x == range_left_) and (y == range_right_))
            return node_score_;
        int range_middle = (range_left_ + range_right_) / 2;
        if (y <= range_middle)
            return left_node_->GetQueryScore(x, y);
        if (x >= range_middle + 1)
            return right_node_->GetQueryScore(x, y);
        tree_node_score left_node_query_score = left_node_->GetQueryScore(x, range_middle);
        tree_node_score right_node_query_score = right_node_->GetQueryScore(range_middle + 1, y);
        tree_node_score current_node_query_score;
        current_node_query_score.left_joint_score = max(left_node_query_score.left_joint_score, left_node_query_score.total_score + right_node_query_score.left_joint_score);
        current_node_query_score.right_joint_score = max(right_node_query_score.right_joint_score, right_node_query_score.total_score + left_node_query_score.right_joint_score);
        current_node_query_score.total_score = left_node_query_score.total_score + right_node_query_score.total_score;
        current_node_query_score.best_score = max(max(max(max(current_node_query_score.left_joint_score, current_node_query_score.right_joint_score), left_node_query_score.best_score), right_node_query_score.best_score), left_node_query_score.right_joint_score + right_node_query_score.left_joint_score);
        return current_node_query_score;
    }
};

//Main procedure
int main(){
    //Step1: input array A
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    //Step2: Build Segement Tree
    TreeNode *root = new TreeNode(0, n - 1);
    root->BuildSegementTree();

    //Step3: Querys and answers
    int m = 0, x = 0, y = 0;
    cin >> m;
    tree_node_score current_score;
    for (int i = 0; i < m; ++i){
        scanf("%d%d", &x, &y);
        current_score = root->GetQueryScore(x - 1, y - 1);
        printf("%d\n", current_score.best_score);
    }
    return 0;
}
