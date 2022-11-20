# https://leetcode.com/problems/two-out-of-three/

# class Solution:
#     def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        
#         final=[]
#         for i in nums1:
#             if i in nums2 or i in nums3:
#                 final.append(i)
#         for j in nums2:
#             if j in nums3:
#                 final.append(j)
                
#         return (set(final))


class Solution:
    def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        a = list_to_set(nums1)
        b = list_to_set(nums2)
        c = list_to_set(nums3)        
        return compare_two_sets(a, b) | compare_two_sets(a, c) | compare_two_sets(b, c)
        
                                    

def list_to_set(nums_x: List[int]):
    set_x = set()
    for i in nums_x:
        set_x.add(i)
    return set_x    
    

def compare_two_sets(s1, s2):
    return set(s1.intersection(s2))