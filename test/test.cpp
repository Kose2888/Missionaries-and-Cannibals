#include <iostream>

#include "gtest/gtest.h"
#include "Node.h"
#include "State.h"
#include "Actions.h"

class Test : public testing::Test {
  protected:
    //uint8_t *buffer;

    void SetUp() override {
    }

    void TearDown() override {
    }
};

//TEST_F(PacketTest, setBuffer) {
//}

TEST(Test, nodeTest){
}

TEST(Test, setStateTest) {
  State s;

  s.setState(3, 0, 3, 0, 0);

  EXPECT_EQ(s.getlM(), 3);
  EXPECT_EQ(s.getrM(), 0);
  EXPECT_EQ(s.getlC(), 3);
  EXPECT_EQ(s.getrC(), 0);
  EXPECT_EQ(s.getBoat(), 0);

  s.viewState();
}

TEST(Test, isStartStateTest) {
  State s;

  s.setState(3, 0, 3, 0, 0);

  EXPECT_TRUE(s.isStartState());

  s.setState(1, 0, 3, 0, 1);

  EXPECT_FALSE(s.isStartState());
}

TEST(Test, isGoalStateTest) {
  State s;

  s.setState(3, 0, 3, 0, 0);

  EXPECT_FALSE(s.isGoalState());

  s.setState(0, 3, 0, 3, 1);

  EXPECT_TRUE(s.isGoalState());
}

TEST(Test, addChildNodeTest) {
  Node *root = new Node;
  Node *child = new Node;

  root->addChild(child);

  child->s.setState(3, 0, 3, 0, 0);

  EXPECT_TRUE(child->s.isStartState());

  EXPECT_EQ(root->children.size(), 1);
  EXPECT_EQ(child->id, 1);
  EXPECT_EQ(child->parent, root);

  Node *child2 = new Node;

  child->addChild(child2);

  EXPECT_EQ(root->children.size(), 1);
  EXPECT_EQ(child2->id, 2);
  EXPECT_EQ(child2->parent, child);

  delete root;
}

TEST(Test, mvOneCTest) {
  Node *root = new Node;
  Actions *a = new Actions;

  root->s.setState(3, 0, 3, 0, 0);

  //Moving Cannibal from left to right
  a->mvOneC(root);

  EXPECT_EQ(root->children[0]->s.getlC(), 2);
  EXPECT_EQ(root->children[0]->s.getrC(), 1);
  EXPECT_EQ(root->children[0]->s.getBoat(), 1);

  root->s.setState(3, 0, 2, 1, 1);

  //Moving Cannibal from right to left
  a->mvOneC(root);

  EXPECT_EQ(root->children[1]->s.getlC(), 3);
  EXPECT_EQ(root->children[1]->s.getrC(), 0);
  EXPECT_EQ(root->children[1]->s.getBoat(), 0);

  delete root;
  delete a;
}
