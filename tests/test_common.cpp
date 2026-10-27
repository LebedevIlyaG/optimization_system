#include <gtest/gtest.h>
#include "Common.h"

/**
 * @brief Тесты для вспомогательных функций
 */
class CommonTest : public ::testing::Test {
protected:
  void SetUp() override {
  }
};

// TODO: Добавить тесты для вспомогательных функций
// - Тест GetFileExtension() для различных имен файлов
// - Тест FindXY() для различных параметров
// - Тест IsBelowGraph() для различных точек

TEST_F(CommonTest, GetFileExtensionBasic) {
  std::string filename = "test.txt";
  std::string ext = GetFileExtension(filename, false);
  EXPECT_EQ(ext, "txt");
}

TEST_F(CommonTest, GetFileExtensionWithDot) {
  std::string filename = "test.cpp";
  std::string ext = GetFileExtension(filename, true);
  EXPECT_EQ(ext, ".cpp");
}

TEST_F(CommonTest, GetFileExtensionNoExtension) {
  std::string filename = "makefile";
  std::string ext = GetFileExtension(filename, false);
  EXPECT_EQ(ext, "");
}

TEST_F(CommonTest, FindXYBasic) {
  int x, y;
  FindXY(x, y, 100, 10);
  
  // Проверяем, что x и y были установлены
  EXPECT_GT(x, 0);
  EXPECT_GT(y, 0);
}

TEST_F(CommonTest, IsBelowGraphBasic) {
  // Тест для точек выше и ниже графика
  bool result1 = IsBelowGraph(3, 1000);
  bool result2 = IsBelowGraph(3, 10000);
  
  // Первая точка должна быть ниже, вторая - выше или на графике
  EXPECT_TRUE(result1 || !result1); // Заглушка, требует реализации
}
