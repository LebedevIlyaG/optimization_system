#include <gtest/gtest.h>
#include "Evolvent.h"
#include "Extended.h"

/**
 * @brief Тесты для класса Evolvent
 */
class EvolventTest : public ::testing::Test {
protected:
  Evolvent* evolvent;
  
  void SetUp() override {
    evolvent = new Evolvent(2, 10);
    double A[] = {-1.0, -1.0};
    double B[] = {1.0, 1.0};
    evolvent->SetBounds(A, B);
  }
  
  void TearDown() override {
    delete evolvent;
  }
};

// TODO: Добавить тесты для класса Evolvent
// - Тест конструктора
// - Тест установки границ
// - Тест прямого отображения (x -> y)
// - Тест обратного отображения (y -> x)
// - Тест граничных случаев (x=0, x=1)
// - Тест одномерного случая

TEST_F(EvolventTest, Constructor) {
  EXPECT_EQ(evolvent->getA()[0], -1.0);
  EXPECT_EQ(evolvent->getB()[0], 1.0);
}

TEST_F(EvolventTest, SetBounds) {
  double A[] = {-5.0, -5.0};
  double B[] = {5.0, 5.0};
  evolvent->SetBounds(A, B);
  
  EXPECT_EQ(evolvent->getA()[0], -5.0);
  EXPECT_EQ(evolvent->getB()[1], 5.0);
}

TEST_F(EvolventTest, GetImageBoundaries) {
  double y[2];
  
  // Тест для x = 0
  Extended x0(0.0);
  evolvent->GetImage(x0, y);
  EXPECT_GE(y[0], -1.0);
  EXPECT_LE(y[0], 1.0);
  
  // Тест для x = 1
  Extended x1(1.0);
  evolvent->GetImage(x1, y);
  EXPECT_GE(y[0], -1.0);
  EXPECT_LE(y[0], 1.0);
}

TEST_F(EvolventTest, OneDimensionalCase) {
  Evolvent evolvent1D(1, 10);
  double A[] = {0.0};
  double B[] = {1.0};
  evolvent1D.SetBounds(A, B);
  
  double y[1];
  Extended x(0.5);
  evolvent1D.GetImage(x, y);
  
  EXPECT_NEAR(y[0], 0.5, 1e-10);
}
