#include "pch.h"
#include "CppUnitTest.h"
#include "C:\\Users\\user\\source\\repos\\ConsoleApplication11\\ConsoleApplication11.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestTree
{
    TEST_CLASS(UnitTest8)
    {
    public:
        TEST_METHOD(Test_IdenticalTrees)
        {
            TreeNode* root1 = new TreeNode(1);
            root1->left = new TreeNode(2);
            root1->right = new TreeNode(3);

            TreeNode* root2 = new TreeNode(1);
            root2->left = new TreeNode(2);
            root2->right = new TreeNode(3);

            Assert::IsTrue(areIdentical(root1, root2));
        }
        TEST_METHOD(Test_DifferentTrees)
        {

            TreeNode* root1 = new TreeNode(1);
            root1->left = new TreeNode(2);
            root1->right = new TreeNode(3);

            TreeNode* root2 = new TreeNode(1);
            root2->left = new TreeNode(2);
            root2->right = new TreeNode(4);

            Assert::IsFalse(areIdentical(root1, root2));
        }
    };
}