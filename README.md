
# ft_printf

`ft_printf`는 C 표준 라이브러리의 `printf` 함수를 직접 구현하여 문자열을 포맷팅하고 출력할 수 있는 함수입니다.

## 목차
- [ft\_printf](#ft_printf)
	- [목차](#목차)
	- [프로젝트 개요](#프로젝트-개요)
	- [함수 개요](#함수-개요)
	- [지원하는 포맷 지정자](#지원하는-포맷-지정자)
	- [구현 세부 사항](#구현-세부-사항)
	- [설치 방법](#설치-방법)
	- [사용 방법](#사용-방법)

## 프로젝트 개요

이 프로젝트는 `ft_printf`라는 함수 구현을 목표로 합니다. 이 함수는 `printf`와 비슷하게 문자열을 포맷하고 출력하는 기능을 제공하여, 다양한 타입의 데이터를 형식화하여 출력할 수 있습니다.

## 함수 개요

```c
int ft_printf(const char *format, ...);
```

- **매개변수**:
  - `format`: 출력할 형식 지정 문자열로, 일반 문자열과 형식 지정자가 포함될 수 있습니다.
  - `...`: 가변 인자를 통해 여러 인자를 받아들입니다.

- **반환값**:
  - 출력된 전체 문자의 수를 반환하며, 오류가 발생한 경우에는 음수를 반환합니다.

## 지원하는 포맷 지정자

`ft_printf`에서는 기본적인 포맷 지정자를 지원합니다.

- `%c` - 단일 문자
- `%s` - 문자열
- `%p` - 포인터 주소
- `%d` - 정수형 숫자 (10진수)
- `%i` - 정수형 숫자 (10진수)
- `%u` - 부호 없는 정수형 숫자 (10진수)
- `%x` - 부호 없는 정수형 숫자 (소문자 16진수)
- `%X` - 부호 없는 정수형 숫자 (대문자 16진수)
- `%%` - `%` 문자 출력

## 구현 세부 사항

- **가변 인자 처리**: `ft_printf`는 `stdarg.h` 라이브러리의 `va_list`를 사용하여 가변 인자를 처리합니다.
- **포맷 분석**: 형식 지정자에 따라 각 데이터를 적절한 형태로 변환하여 출력합니다.
- **출력 관리**: `write` 함수를 사용하여 표준 출력으로 출력하며, 각 인자에 맞게 형식을 조정합니다.
- **포인터 처리**: 포인터 주소는 `0x` 접두사를 붙이고 16진수 형식으로 출력합니다.

## 설치 방법

1. 터미널에서 이 저장소를 클론합니다.
    ```bash
    git clone https://github.com/jmsmg/ft_printf.git
    cd ft_printf
    ```

2. 필요한 파일을 컴파일합니다.
    ```bash
    make
    ```

3. 컴파일 후 `libftprintf.a`라는 정적 라이브러리 파일이 생성됩니다.

## 사용 방법

`ft_printf` 함수는 다음과 같이 사용할 수 있습니다.

```c
#include "ft_printf.h"

int main(void) {
    int len;

    len = ft_printf("Hello, %s!
", "World");
    ft_printf("Printed %d characters.
", len);

    return 0;
}
```