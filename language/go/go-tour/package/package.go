package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	fmt.Println("My favorite number is", rand.Intn(time.Now().Second()))
}
