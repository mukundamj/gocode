package mystore

//type Exception struct {
//    Message string `json:"message"`
//}

type Product struct {
  ID int `bson:"_id"`
  Name string `json:"name,omitempty"`
  Description string `json:"description,omitempty"`
  Category string `json:"category,omitempty"`
  ProductType string `json:"productType,omitempty"`
  Price float32 `json:"price,omitempty"`
  InStock bool `json:"inStock,omitempty"`
  Manufacturer string `json:"manufacturer,omitempty"`
}

type Products []Product
