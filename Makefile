LIB=			libbubble.dll
CC=				g++
CC_FLAGS=		-Wall -Wextra -Werror -fPIC
SRC_DIR=		src
INCLUDE_DIR=	$(SRC_DIR)/include
DEST_DIR=		bin
SRCS=			$(wildcard $(SRC_DIR)/*.cpp)
OBJS=			$(patsubst %.cpp,%.o, $(SRCS))

all: $(OBJS)
	$(CC) -shared $(wildcard $(DEST_DIR)/*.o) -o $(DEST_DIR)/$(LIB)

%.o: %.cpp
	@mkdir -p $(DEST_DIR)
	$(CC) $(CC_FLAGS) -I$(INCLUDE_DIR) -c $< -o $(DEST_DIR)/$(@F)

clean:
	rm -rf $(DEST_DIR)