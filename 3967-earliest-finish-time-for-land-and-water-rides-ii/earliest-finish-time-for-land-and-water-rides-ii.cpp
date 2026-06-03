class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        vector<pair<int, int>> land, water;

        for (int i = 0; i < n; i++)
            land.push_back({landStartTime[i], landDuration[i]});

        for (int i = 0; i < m; i++)
            water.push_back({waterStartTime[i], waterDuration[i]});

        sort(land.begin(), land.end());
        sort(water.begin(), water.end());

        vector<int> landStarts(n), waterStarts(m);

        vector<int> prefLand(n), prefWater(m);
        vector<int> sufLand(n), sufWater(m);

        for (int i = 0; i < n; i++)
            landStarts[i] = land[i].first;

        for (int i = 0; i < m; i++)
            waterStarts[i] = water[i].first;

        prefLand[0] = land[0].second;
        for (int i = 1; i < n; i++)
            prefLand[i] = min(prefLand[i - 1], land[i].second);

        prefWater[0] = water[0].second;
        for (int i = 1; i < m; i++)
            prefWater[i] = min(prefWater[i - 1], water[i].second);

        sufLand[n - 1] = land[n - 1].first + land[n - 1].second;
        for (int i = n - 2; i >= 0; i--)
            sufLand[i] = min(sufLand[i + 1], land[i].first + land[i].second);

        sufWater[m - 1] = water[m - 1].first + water[m - 1].second;
        for (int i = m - 2; i >= 0; i--)
            sufWater[i] =
                min(sufWater[i + 1], water[i].first + water[i].second);

        int ans = INT_MAX;

        // Land -> Water
        for (int i = 0; i < n; i++) {
            int finishLand = landStartTime[i] + landDuration[i];

            int idx = upper_bound(waterStarts.begin(), waterStarts.end(),
                                  finishLand) -
                      waterStarts.begin();

            if (idx > 0)
                ans = min(ans, finishLand + prefWater[idx - 1]);

            if (idx < m)
                ans = min(ans, sufWater[idx]);
        }

        // Water -> Land
        for (int i = 0; i < m; i++) {
            int finishWater = waterStartTime[i] + waterDuration[i];

            int idx =
                upper_bound(landStarts.begin(), landStarts.end(), finishWater) -
                landStarts.begin();

            if (idx > 0)
                ans = min(ans, finishWater + prefLand[idx - 1]);

            if (idx < n)
                ans = min(ans, sufLand[idx]);
        }

        return ans;
    }
};