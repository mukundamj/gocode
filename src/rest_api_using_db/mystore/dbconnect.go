package mystore

import (
  "gopkg.in/mgo.v2"
  "log"
)

type Storage struct{}
const SERVER = "mongodb://127.0.0.1:27017"
const DBNAME = "MyProducts"
const COLLECTION = "Products"

var productId = 0;

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
    log.Println("Failed to get product. Err :", err)
  }
  return aProduct
}

func (s Storage) UpdateProduct(product Product) bool {
  session, err := mgo.Dial(SERVER)
  defer session.Close()
  err = session.DB(DBNAME).C(COLLECTION).UpdateId(product.ID, product)
  if err != nil {
    log.Println("Product ID not found")
    log.Println(err)
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
    log.Println("Product ID not found")
    log.Println(err)
    return "400 BAD REQUEST"
  }

  log.Println("A product deleted from db having ID - ", id)
  return "OK"
}
