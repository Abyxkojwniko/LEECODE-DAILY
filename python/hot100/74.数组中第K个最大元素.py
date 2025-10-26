class Solution:
    # 启用三路快排分区
    def partition(self, nums: List[int], left: int, right: int) -> tuple[int, int]:
        # 1. 随机选择基准，并交换到 left (修正语法)
        random_index = random.randint(left, right)
        nums[left], nums[random_index] = nums[random_index], nums[left]
        
        pivot = nums[left] # 2. 正确获取基准值
        
        lt = left      # nums[left..lt] < pivot 的区域末尾
        gt = right     # nums[gt..right] > pivot 的区域开头
        i = left + 1   # nums[lt+1..i-1] = pivot 的区域
        
        while i <= gt:
            if nums[i] < pivot:
                # 将 < pivot 的元素换到 = pivot 区域的开头
                nums[i], nums[lt + 1] = nums[lt + 1], nums[i]
                lt += 1
                i += 1
            elif nums[i] > pivot:
                # 将 > pivot 的元素换到 gt 位置
                nums[i], nums[gt] = nums[gt], nums[i]
                gt -= 1 
                # i 不动，因为新换回来的 nums[i] 还需要检查
            else:
                # = pivot 的元素，继续向右扫描
                i += 1
                
        # 将基准值换到正确位置：换到小于区域的末尾
        # 此时 lt 是小于区域的最后一个元素索引，交换后 nums[lt] = pivot
        nums[left], nums[lt] = nums[lt], nums[left]
        
        # 返回等于 pivot 元素的范围 [lt, gt]
        return lt, gt

    def findKthLargest(self, nums: List[int], k: int) -> int:
        # 必须在调用前初始化随机数生成器，虽然 random.randint() 通常不需要，但保持习惯是好的。
        # random.seed() # 如果需要可重现的结果，可以设置种子
        
        n = len(nums)
        target = n - k # 第 k 大转换为第 n-k 小 (索引)
        left, right = 0, n - 1
        
        while left <= right:
            lt, gt = self.partition(nums, left, right)
            
            if target >= lt and target <= gt:
                # 目标索引在等于 pivot 的区域内，找到了！
                return nums[target]
            elif target < lt:
                # 目标在小于 pivot 的区域内
                right = lt - 1
            else: # target > gt
                # 目标在大于 pivot 的区域内
                left = gt + 1
                
        return -1 # 理论上不会发生