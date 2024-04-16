#ifndef RATIONAL_LIB_HPP
#define RATIONAL_LIB_HPP
#include <cstdint>
#include <iostream>
#include <stdexcept>


class Rational {
public:
  Rational() = default; /// ���� ������ �� �������� (�������� �� ���������)
  Rational(int64_t num, int64_t den) : num_(num), den_(den) { fix(); } /// ���� �� ���� �������� 2 �����
  explicit Rational(int64_t num) : Rational{ num, 1 } {} /// ���� �� ���� �������� ������ 1 ����� /// explicit + c����� ������ ������������� ����� (direct initialization)
  ~Rational() = default; /// ����������
  Rational(const Rational& rhs) = default; /// �������� �� ���� ������  Rational A(1, 2) -> Rational B(A)
  Rational& operator=(const Rational& rhs) { num_ = rhs.num_; den_ = rhs.den_; return *this; } /// �������� ������������


  [[nodiscard]] int64_t num() const { return num_; }
  [[nodiscard]] int64_t den() const { return den_; }


  /// ��������� ��������� (���������):
  bool operator==(const Rational& rhs) const { return num_ * rhs.den_ == rhs.num_ * den_; } /// �������� ==
  bool operator==(const int64_t rhs) const { return num_ * 1 == rhs * den_; }

  bool operator!=(const Rational& rhs) const { return num_ * rhs.den_ != rhs.num_ * den_; } /// �������� !=
  bool operator!=(const int64_t rhs) const { return !operator==(rhs); } /// ���� �������� !=, �� ���������� ����� �������� ==

  bool operator>(const Rational& rhs) const { return rhs.den_ * num_ > rhs.num_ * den_; } /// �������� >
  bool operator>(const int64_t rhs) const { return 1 * num_ > rhs * den_; }

  bool operator>=(const Rational& rhs) const { return operator==(rhs) || operator>(rhs); } /// �������� >=
  bool operator>=(const int64_t rhs) const { return operator==(rhs) || operator>(rhs); }

  bool operator<=(const Rational& rhs) const { return !operator>(rhs); } /// �������� <= (������� ����� �������� > )
  bool operator<=(const int64_t rhs) const { return !operator>(rhs); }

  bool operator<(const Rational& rhs) const { return operator<=(rhs) && !operator==(rhs); } /// �������� < (������� ����� <= � �� �������� ==)
  bool operator<(const int64_t rhs) const { return operator<=(rhs) && !operator==(rhs); }

  /// ��������� ��������������:
  Rational& operator+=(const Rational& rhs); /// ���������� ��������� +=
  Rational& operator+=(const int64_t rhs) { return operator+=(Rational(rhs)); } /// ���������� � �����������

  Rational& operator-=(const Rational& rhs); /// �������� -=
  Rational& operator-=(const int64_t rhs) { return operator-=(Rational(rhs)); }

  Rational& operator*=(const Rational& rhs); /// �������� *=
  Rational& operator*=(const int64_t rhs) { return operator*=(Rational(rhs)); }

  Rational& operator/=(const Rational& rhs); /// �������� /=
  Rational& operator/=(const int64_t rhs) { return operator/=(Rational(rhs)); }

  std::istream& input(std::istream& read); /// ������ ��� ��, ���� �� ����������  ��������
  std::ostream& output(std::ostream& write) const; /// ����� �������� � ��, �� ������ ��, ��� �� �����

private:
  int64_t num_ = 0; /// ��������� 
  int64_t den_ = 1; /// �����������
  char separator = '/'; /// ��������� 

  int64_t gcd(int64_t a, int64_t b) { /// ���, ��������� ������� �� ��������
    if (a * b == 0) {
      return a + b; /// ��� ���
    }
    else if (a > b) {
      return gcd(a % b, b);
    }
    else {
      return gcd(b % a, a);
    }
  }

  void fix() {
    bool is_positive = (num_ * den_ >= 0 ? true : false); /// ���� �����
    num_ = std::abs(num_);
    den_ = std::abs(den_);
    int64_t nod = gcd(num_, den_);
    num_ /= nod;
    den_ /= nod;
    num_ = (is_positive ? num_ : -num_);
  }


};

std::istream& operator>>(std::istream& stream, Rational& rhs) { return rhs.input(stream); }
std::ostream& operator<<(std::ostream& stream, Rational& rhs) { return rhs.output(stream); }

#endif