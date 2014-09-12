#include <algorithm>
#include <iostream>
#include <cstdio>
#include <memory>
#include <limits>

int main() {
    double d;
    const double& seconds_in_half_day = 12.0 * 60.0;

    // ==========================================
    while (scanf("%lf", &d) != EOF && d >= 0.0) {
        // 每12小时秒针转12 * 60圈
        // 每12小时时针转1圈
        // 每12小时秒针追上时针12 * 60 - 1次

        double cur_m_d = 0.0; // 当前分针度数
        double sum_degree = 0.0;
        // 以时针为原点，秒针每秒转 719/120°，每°要消耗120/719秒
        // 以时针为原点，分针每秒转  11/120°，分针度数 = cur_m_d + 秒针度数 * 11 / 719
        // 以时针为原点，秒针共转 12 * 60 - 1 圈
        for (int i = 0; i < 12 * 60 - 1; ++i) {
            // 1. 秒针在分针前, 分针在时针前
            // cur_m_d + s * 11 / 719 - s >= d => s <= (cur_m_d - d) * 719 / 708
            // d <= s
            // 360 - (cur_m_d + s * 11 / 719) >= d => s <= (360 - cur_m_d - d) * 719 / 11
            double s_d = (cur_m_d - d) * 719 / 708;
            s_d = std::min<double>(s_d, (360.0 - cur_m_d - d) * 719 / 11);
            if (s_d >= d)
                sum_degree += s_d - d;

            // 2. 秒针在分针前, 分针在时针后
            // d <= s
            // 360 - s >= d  =>  s <= 360 - d
            // (cur_m_d + s * 11 / 719) - 360 >= d => s >= (360 + d - cur_m_d) * 719 / 11
            s_d = (360 + d - cur_m_d) * 719 / 11;
            s_d = std::max<double>(s_d, d);
            if (s_d <= 360 - d)
                sum_degree += 360 - d - s_d;

            // 3. 秒针在分针后
            // s - (cur_m_d + s * 11 / 719) >= d  =>   s >= (d + cur_m_d) * 719 / 708
            // cur_m_d + s * 11 / 719 >= d  =>  s >= (d - cur_m_d) * 719 / 11
            // 360 - s >= d  =>  s <= 360 - d
            s_d = (d + cur_m_d) * 719 / 708;
            s_d = std::max<double>(s_d, (d - cur_m_d) * 719 / 11);
            if (s_d <= 360 - d)
                sum_degree += 360 - d - s_d;

            cur_m_d += 360.0 * 11 / 719;
            while (cur_m_d >= 360.0)
                cur_m_d -= 360.0;
        }

        printf("%.03lf\n", sum_degree * 100.0 / (12 * 60 - 1) / 360.0);
    }
    return 0;
}
