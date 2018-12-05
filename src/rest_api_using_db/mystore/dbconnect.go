package mystore

import (
  //"fmt"
  "gopkg.in/mgo.v2"
  "log"
  //"gopkg.in/mgo.v2/bson"
  //"strings"
)

type Storage struct{}
const SERVER = "mongodb://127.0.0.1:27017"
const DBNAME = "MyProducts"
const COLLECTION = "Products"

var productId = 3;

func (s Storage) GetProducts() Products {
  session, err := mgo.Dial(SERVER)
  if err != nil {
    log.Println("Connection to Mongo server couldn't be established:", err)
  }
  defer session.Close()
  c := session.DB(DBNAME).C(COLLECTION)
  allProducts := Products{}
  if err := c.Find(nil).All(&allProducts); err != nil {
    log.Println("Failed to write allProducts:", err)
  }
  log.Println("Fetched all products data from db")
  return allProducts
}

func (s Storage) GetProductById(id int) Product {
  session, err := mgo.Dial(SERVER)
  if err != nil {
    log.Println("Connection to Mongo server couldn't be established:", err)
  }
  defer session.Close()
  c := session.DB(DBNAME).C(COLLECTION)
  var aProduct Product
  if err := c.FindId(id).One(&aProduct); err != nil {
    log.Println("Failed to write aProduct:", err)
  }
  log.Println("Fetched a product by ID from db")
  return aProduct
}

func (s Storage) UpdateProduct(product Product) bool {
  session, err := mgo.Dial(SERVER)
  defer session.Close()
  err = session.DB(DBNAME).C(COLLECTION).UpdateId(product.ID, product)
  if err != nil {
    log.Fatal(err)
    return false
  }
  log.Println("Product updated for the ID - ", product.ID)
  return true
}

func (s Storage) AddProduct(product Product) bool {
  session, err := mgo.Dial(SERVER)
  defer session.Close()
  productId += 1
  product.ID = productId
  session.DB(DBNAME).C(COLLECTION).Insert(product)
  if err != nil {
    log.Fatal(err)
    return false
  }
  log.Println("A Product added to the database having ID - ", product.ID)
  return true
}

func (s Storage) DeleteProduct(id int) string {
  session, err := mgo.Dial(SERVER)
  defer session.Close()
  if err = session.DB(DBNAME).C(COLLECTION).RemoveId(id); err != nil {
    log.Fatal(err)
    return "INTERNAL ERR"
  }

  log.Println("A product deleted from db having ID - ", id)
  return "OK"
}
