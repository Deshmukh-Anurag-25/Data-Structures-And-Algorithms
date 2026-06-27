#pragma once

struct Node {
  int val;
  Node *left;
  Node *right;

  Node() : val(0), left(nullptr), right(nullptr) {}
  Node(int val) : val(val), left(nullptr), right(nullptr) {}
  Node(int val, Node *left, Node *right) : val(val), left(left), right(right) {}
};
