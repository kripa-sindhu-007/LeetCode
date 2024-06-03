class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int sum = accumulate(skill.begin(), skill.end(), 0);
        int target = sum / (skill.size() / 2);
        sort(skill.begin(), skill.end());
        int beg = 0, end = skill.size() - 1;
        long long chem = 0;
        int count = 0;
        while (beg < end) {
            if (skill[beg] + skill[end] == target) {
                chem += skill[beg++] * skill[end--];
                count++;
            } else if (skill[beg] + skill[end] > target)
                end--;
            else
                beg++;
        }
        if (count == skill.size() / 2)
            return chem;
        else
            return -1;
    }
};