# Problem: Finding Superior Elements
**Problem Link:** <a href="https://www.codingninjas.com/studio/problems/superior-elements_6783446"> Click here </a>
## Approach 🛠️

### Intuition 🤔
We want to find the superior elements in the given array `a`. A superior element is defined as an element in the array that is greater than all elements to its right.

### Approach 🛠️
- We start by initializing an empty vector `ans` to store the superior elements.
- We iterate through the elements of the array `a` in reverse order (from right to left) using a `for` loop.
- We maintain a variable `maxsmaller` to keep track of the maximum element encountered so far while iterating in reverse.
- For each element `a[i]` in the array:
  - If `a[i]` is greater than `maxsmaller`, it is a superior element, so we add it to the `ans` vector, and update `maxsmaller` to `a[i]`.
- Finally, we return the `ans` vector containing the superior elements.

### Time Complexity ⏳
- The algorithm iterates through the array once in reverse order, so the time complexity is O(N), where N is the size of the input array `a`.

### Space Complexity 🚀
- We use an additional vector `ans` to store the superior elements. The space complexity is O(M), where M is the number of superior elements in the input array `a`.
- In the worst case, when all elements are superior, the space complexity would be O(N) as well.

Overall, this algorithm efficiently finds and stores the superior elements in the given array.
