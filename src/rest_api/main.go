package main

import (
  "encoding/json"
  "log"
  "net/http"
  "github.com/gorilla/mux"
)

type Product struct {
  Name string `json:"Name,omitempty"`
  Description string `json:"Description,omitempty"`
  Category string `json:"Category,omitempty"`
  ProductType string `json:"ProductType,omitempty"`
  Price float32 `json:"Price,omitempty"`
  InStock bool `json:"InStock,omitempty"`
  Manufacturer string `json:"Manufacturer,omitempty"`
}

type Products []Product

var products = Products {
  Product {
    Name : "iPhoneXs",
    Description : "The phone with elegant design",
    Category : "Smartphones",
    ProductType : "5.8 inch",
    Price : 999.00,
    InStock : true,
    Manufacturer : "Apple",
  },
  Product {
    Name : "iPadPro",
    Description : "Bigger than iPhone and smaller than MacBook",
    Category : "Tablets",
    ProductType : "11 inch",
    Price : 799.00,
    InStock : true,
    Manufacturer : "Apple",
  },
}

func GetProducts(w http.ResponseWriter, r *http.Request) {
  json.NewEncoder(w).Encode(products)
}

func GetProduct(w http.ResponseWriter, r *http.Request) {
  params := mux.Vars(r)
  for _, item := range products {
    if item.Name == params["id"] {
      json.NewEncoder(w).Encode(item)
      return
    }
  }
  json.NewEncoder(w).Encode(&Products{})
}

func CreateProduct(w http.ResponseWriter, r *http.Request) {
  params := mux.Vars(r)
  var product Product
  _ = json.NewDecoder(r.Body).Decode(&product)
  product.Name = params["id"]
  products = append(products, product)
  json.NewEncoder(w).Encode(products)
}

func DeleteProduct(w http.ResponseWriter, r *http.Request) {
  params := mux.Vars(r)
  for index, item := range products {
    if item.Name == params["id"] {
      products = append(products[:index], products[index+1:]...)
      break
    }
    json.NewEncoder(w).Encode(products)
  }
}

//Comment TODO
func main() {
  //setup mux router
  router := mux.NewRouter()

  router.HandleFunc("/tenant/products", GetProducts).Methods("GET")
  router.HandleFunc("/tenant/products/{id}", GetProduct).Methods("GET")
  router.HandleFunc("/tenant/products/{id}", CreateProduct).Methods("POST")
  router.HandleFunc("/tenant/products/{id}", DeleteProduct).Methods("DELETE")
  //spin-up golang server
  log.Fatal(http.ListenAndServe(":8000", router))
}
