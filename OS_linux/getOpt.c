#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// getopt() 와 관련된 전역 변수

// optarg : 옵션 뒤에 별도의 파라미터 값이 오는 경우, 이를 파싱한 결과 파라미터 값은 optarg에 문자열로 저장된다.
// optind : 다음번 처리될 옵션의 인덱스이다. 만약 파싱한 옵션이후에 추가적인 파라미터를 받는다면 (예를 들어 입력 파일 이름 같이) 이 값을 활용할 수 있다. getopt()함수는 한 번 호출될 때마다 이 값을 업데이트한다.
// opterr : 옵션에 문제가 있을 때, 이 값은 0이 아닌 값이되며, getopt()함수가 메시지를 표시하게 된다.
// optopt : 알 수 없는 옵션을 만났을 때 해당 옵션이 여기에 들어간다. (이 때 getopt의 리턴값은 ‘?’가 된다.)
int
main(int argc, char *argv[])
{
    int flags, opt;
    int nsecs, tfnd;

    nsecs = 0;
    tfnd = 0;
    flags = 0;
    while ((opt = getopt(argc, argv, "nt:")) != -1) {
        switch (opt) {
        case 'n':
            flags = 1;
            break;
        case 't':
            nsecs = atoi(optarg);
            tfnd = 1;
            break;
        default: /* '?' */
            fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n",
                    argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    printf("flags=%d; tfnd=%d; nsecs=%d; optind=%d\n",
            flags, tfnd, nsecs, optind);

    if (optind >= argc) {
        fprintf(stderr, "Expected argument after options\n");
        exit(EXIT_FAILURE);
    }

    printf("name argument = %s\n", argv[optind]);

    /* Other code omitted */

    exit(EXIT_SUCCESS);
}