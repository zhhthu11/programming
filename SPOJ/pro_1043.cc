#include <iostream>
#include <math.h>
using namespace std;

//Every TreeNode has a tree_node_score
struct tree_node_score{
  int left_joint_score;     //join as a left node, at least one element count
  int right_joint_score;    //join as a right node, at least one element count
  int total_score;          //total score of this node
  int best_score;           //best score of this node
  
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
  };

  tree_node_score SearchQueryAnswer(int x, int y){
    if ((x == range_left_) and (y == range_right_))
      return node_score_;
    return tree_node_score();
  }
};

//Main procedure
int main(){
  TreeNode* test = new TreeNode(1, 10);
  tree_node_score current_score = test->SearchQueryAnswer(1,10);
  cout << current_score.best_score << endl;
  return 0;
}

