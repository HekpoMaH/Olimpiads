#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

int nextx[] = {1, -1, 0, 0};
int nexty[] = {0, 0, 1, -1};

inline short int calculateFuelForWind(int x, int y, int nx, int ny, int windDirectionArg, int windSpeedArg, int S) {
  int wx = x + nextx[windDirectionArg];
  int wy = y + nexty[windDirectionArg];
  int manhattan = abs(wx - nx) + abs(wy - ny);
  int dx = wx - x;
  int dy = wy - y;
  if(dx == -nx && dy == -ny) {
    manhattan = 4;
  }

  int windSpeed = windSpeedArg - manhattan;
  if (windSpeed < 0) {
    windSpeed = 0;
  }
  int engineSpeed = S - windSpeed;
  if (engineSpeed <= 0) {
    return 0;
  }
  int res = (((engineSpeed - 1) / 3) + 1);
  return res;
}

const int MAX_N = 1 << 10;
const int MAX_REGIONS = 1 << 20;

int N;
int M;
int duration;
int updates;
int ship_speed;
int initial_regions;
int start_x;
int start_y;
int end_x;
int end_y;

int all_regions;

short active_region[MAX_N][MAX_N];
short dp[2][MAX_N][MAX_N];

inline void addRegion(int region_id, int x1, int y1, int x2, int y2) {
  for (int i = x1; i <= x2; ++i) {
    for (int j = y1; j <= y2; ++j) {
      active_region[i][j] = region_id;
    }
  }
}

inline void addRegions(int count) {
  int x1;
  int y1;
  int x2;
  int y2;
  int region_id;
  for (int i = 0; i < count; ++i) {
    scanf("%d %d %d %d %d", &region_id, &x1, &y1, &x2, &y2);
    addRegion(region_id, x1, y1, x2, y2);
  }
}

int direction[MAX_REGIONS];
int speed[MAX_REGIONS];

inline void updateWind() {
  int activeRegions;
  scanf("%d", &activeRegions);
  for (int i = 0; i < activeRegions; ++i) {
    int region_id;
    int dir;
    int local_speed;
    scanf("%d %d %d", &region_id, &dir, &local_speed);
    direction[region_id] = dir - 1;
    speed[region_id] = local_speed;
  }
}

inline void handleUpdate() {
//  printf("handling update\n");
  int new_regions;
  scanf("%d", &new_regions);
  addRegions(new_regions);
  all_regions += new_regions;
  updateWind();
}

inline int getNextUpdateTime(int current_time, int current_update) {
  if (current_update >= updates) {
    return SHRT_MAX;
  }
  static int next_time = -1;
  if (next_time < current_time) {
    scanf("%d", &next_time);
  }
  return next_time;
}

int main() {
  scanf("%d %d", &N, &M);
  scanf("%d %d %d %d", &duration, &updates, &ship_speed, &initial_regions);
  all_regions = initial_regions;
  scanf("%d %d", &start_x, &start_y);
  scanf("%d %d", &end_x, &end_y);

  addRegions(initial_regions);
  memset(dp, 63, sizeof(dp));
    
  dp[0][start_x][start_y] = 0;
  int current_update = 0;
  int res = SHRT_MAX;
  int best_time = -1;
  int rstartx = max(0, start_x - duration);
  int rendx = min(N, start_x + duration);
  int rstarty = max(0, start_y - duration);
  int rendy = min(M, start_y + duration);
  for (int time = 1; time < duration; ++time) {
    if (getNextUpdateTime(time, current_update) == time) {
      handleUpdate();
      ++current_update;
    }

    for (int next_x = 0; next_x < N; ++next_x) {
      for (int next_y = 0; next_y < M; ++next_y) {
        dp[time & 1][next_x][next_y] = SHRT_MAX;
        for (int dir = 0; dir < 4; ++dir) {
          int i = next_x - nextx[dir];
          int j = next_y - nexty[dir];
          if (i < rstartx || i >= rendx || j < rstarty || j >= rendy) {
            continue;
          }
          dp[time & 1][next_x][next_y] = min(dp[time & 1][next_x][next_y],
             (short int)(dp[time - 1 & 1][i][j] + calculateFuelForWind(i, j, next_x, next_y, direction[active_region[i][j]], speed[active_region[i][j]], ship_speed)));
        }
      }
    }

    if (dp[time & 1][end_x][end_y] < res) {
      res = dp[time & 1][end_x][end_y];
      best_time = time;
    }
  }

  printf("%d\n", res);
}
