class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        n = len(skill)
        skill.sort()
        
        total_skill = sum(skill)
        pair_count = n // 2
        target_sum = total_skill // pair_count
        
        chemistry_sum = 0
        
        for i in range(pair_count):
            pair_sum = skill[i] + skill[n - 1 - i]
            if pair_sum != target_sum:
                return -1
            chemistry_sum += skill[i] * skill[n - 1 - i]
        
        return chemistry_sum
