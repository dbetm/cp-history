from typing import List


class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        output = list()
        min_sum = 5000

        hashmap1 = {string: idx for idx, string in enumerate(list1)}
        hashmap2 = {string: idx for idx, string in enumerate(list2)}

        for key, idx in hashmap1.items():
            if key in hashmap2:
                sum_ = idx + hashmap2[key]

                if sum_ < min_sum:
                    min_sum = sum_
                    output = [key]
                elif sum_ == min_sum:
                    output.append(key)
                else:
                    pass

        return output



if __name__ == "__main__":
    sol = Solution()

    list1 = ["happy","sad","good"] #["Shogun","Tapioca Express","Burger King","KFC"]
    list2 = ["sad","happy","good"] # ["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]

    print(sol.findRestaurant(list1, list2))
