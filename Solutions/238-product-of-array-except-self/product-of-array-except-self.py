class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        # Initialize result array with zeros
        result = [0] * n
      
        # First pass: calculate products of all elements to the left
        left_product = 1
        for i in range(n):
            # Store the product of all elements before current index
            result[i] = left_product
            # Update left_product for next iteration
            left_product *= nums[i]
      
        # Second pass: multiply by products of all elements to the right
        right_product = 1
        for i in range(n - 1, -1, -1):
            # Multiply existing left product by right product
            result[i] *= right_product
            # Update right_product for next iteration
            right_product *= nums[i]
      
        return result