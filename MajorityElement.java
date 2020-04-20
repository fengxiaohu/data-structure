import java.util.HashMap;
import java.util.Map;
import java.lang.reflect.Array;
class Solution{
    private Map<Integer,Integer> countNums(int[] nums)
    {
    Map<Integer,Integer> counts = new HashMap<Integer,Integer>();//create a new hashmap
        for(int num:nums)
        {
            if(!counts.containsKey(num)) counts.put(num,1);
            /*
            judge whether num
            java.util.Map.containsKey(Object key)
                Returns true if this map contains a mapping for the specified key
            Integer java.util.Map.put(Integer key, Integer value)

            Integer java.util.Map.put(Integer key, Integer value)
            Associates the specified value with the specified key in this map (optional operation). 
            If the map previously contained a mapping for the key, the old value is replaced by the specified value.   
            */
            else counts.put(num,counts.get(num)+1);
        }
        return counts;
    }

    public int majorityElement(int[] nums)
    {
        Map<Integer,Integer> counts = countNums(nums);
        Map.Entry<Integer,Integer> majorityEntry = null;
        for(Map.Entry<Integer,Integer> entry:counts.entrySet())
        {
            if(majorityEntry==null|| entry.getValue()>majorityEntry.getValue())
            {
                majorityEntry = entry;
            }
        }
        return majorityEntry.getKey();
    }
class Solution2{
    public int majorityElement(int[] nums)
    {
        Arrays.sort(nums);

    }
}


