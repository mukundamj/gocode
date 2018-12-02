package main

import (
  "encoding/json"
  "log"
  "net/http"
  "github.com/gorilla/mux"
)

type Product struct {
  name string `json:"name,omitempty"`
  description string `json:"description,omitempty"`
  //category string `json:"category,omitempty"`
  //productType string `json:"productType,omitempty"`
  //price float32 `json:"price,omitempty"`
  //inStock bool `json:"inStock,omitempty"`
  //manufacturer string `json:"manufacturer,omitempty"`
}

var products []Product

func GetProducts(w http.ResponseWriter, r *http.Request) {
  json.NewEncoder(w).Encode(products)
}

func GetProduct(w http.ResponseWriter, r *http.Request) {}

func CreateProduct(w http.ResponseWriter, r *http.Request) {}

func DeleteProduct(w http.ResponseWriter, r *http.Request) {}

//Comment TODO
func main() {
  //setup mux router
  router := mux.NewRouter()

  products = append(products, Product {name : "iPhone Xs", description : "The phone with elegant design"})
  //products = append(products, Product {name : "iPhone Xs", description : "The phone with elegant design", category : "Smartphones", productType : "5.8 inch", price : 999.00, inStock : true, manufacturer : "Apple"})

  //products = append(products, Product {name : "iPad Pro", description : "Bigger than iPhone and smaller than MacBook", category : "Tablets", productType : "11 inch", price : 799.00, inStock : true, manufacturer : "Apple"})

  //products = append(products,
  //  Product {
  //    name : "iPhone Xs",
  //    description : "The phone with elegant design",
  //    category : "Smartphones",
  //    productType : "5.8 inch",
  //    price : 999.00,
  //    inStock : true,
  //    manufacturer : "Apple",
  //  },
  //)
  //products = append(products,
  //  Product {
  //    name : "iPad Pro",
  //    description : "Bigger than iPhone and smaller than MacBook",
  //    category : "Tablets",
  //    productType : "11 inch",
  //    price : 799.00,
  //    inStock : true,
  //    manufacturer : "Apple",
  //  },
  //)

  router.HandleFunc("products", GetProducts).Methods("GET")
  //router.HandleFunc("products/{id}", GetProduct).Methods("GET")
  //router.HandleFunc("products/{id}", CreateProduct).Methods("POST")
  //router.HandleFunc("products/{id}", DeleteProduct).Methods("DELETE")
  //spin-up golang server
  log.Fatal(http.ListenAndServe(":8080", router))
}
