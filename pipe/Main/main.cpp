#include <unistd.h>

int main() {
    // MAPS

    int from_M_to_A[2];
    pipe(from_M_to_A);

    int pid = fork();

    if (pid != 0) {
        pid = fork();

        int from_A_to_P[2];
        pipe(from_A_to_P);

        if (pid != 0) {
            pid = fork();

            int from_P_to_S[2];
            pipe(from_P_to_S);

            if (pid != 0) {
                dup2(from_P_to_S[0], 0);

                execv("S", reinterpret_cast<char *const *>("aRGV"));
            } else {
                dup2(from_A_to_P[0], 0);
                dup2(from_P_to_S[1], 1);

                execv("P", reinterpret_cast<char *const *>("aRGV"));
            }
        } else {
            dup2(from_M_to_A[0], 0);
            dup2(from_A_to_P[1], 1);

            execv("A", reinterpret_cast<char *const *>("aRGV"));
        }
    } else {
        dup2(from_M_to_A[1], 1);
        execv("M", reinterpret_cast<char *const *>("aRGV"));
    }
    return 0;
}
