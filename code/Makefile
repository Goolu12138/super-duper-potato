# 编译器和编译选项
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# 目标文件
TARGET = bin/yahtzee

# 源文件和对象文件
SRCS = main.cpp dice.cpp yahtzee_combination.cpp globals.cpp
OBJS = $(SRCS:.cpp=.o)
OBJDIR = fruits
BINDIR = bin

# 为了在 obj 和 bin 目录中放置对象文件和可执行文件
OBJS := $(addprefix $(OBJDIR)/, $(notdir $(OBJS)))

# 目标
all: $(TARGET)

# 创建目标目录
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

# 链接
$(TARGET): $(OBJS) | $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# 编译
$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# 伪目标
.PHONY: all clean

