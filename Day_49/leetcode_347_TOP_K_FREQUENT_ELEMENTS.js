var topKFrequent = function(nums, k) {
    const map = new Map();
    // Initialize buckets: index represents frequency
    // We use nums.length + 1 because an element could appear up to n times
    const buckets = Array.from({ length: nums.length + 1 }, () => []);
    const result = [];

    // 1. Build the frequency map
    for (let num of nums) {
        map.set(num, (map.get(num) || 0) + 1);
    }

    // 2. Populate the buckets
    // map.entries() gives us [number, frequency]
    for (let [num, freq] of map.entries()) {
        buckets[freq].push(num);
    }

    // 3. Iterate backwards from the highest frequency bucket
    for (let i = buckets.length - 1; i >= 0 && result.length < k; i--) {
        if (buckets[i].length > 0) {
            // Add elements from this bucket until we hit k
            for (let num of buckets[i]) {
                result.push(num);
                if (result.length === k) return result;
            }
        }
    }

    return result;
};