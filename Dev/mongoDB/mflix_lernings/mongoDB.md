# atlas
0. cluster consists of multiple servers and storage devices that manage our database. we can have shared or indipendent clusture.
1. organisation -> project -> -> clusture -> database 
                                          -> users
2. connection string: mongodb://<user>:<password>@<host/port of server storing the databse>,<host2>,<host3>/<database>
ex.: mongodb://localhost:27017
    . if there are huge number of host servers combinely managing the server, uri will become very big, 
    . and if any of the host name/ port changes, we will have to change the string.
    . so, we use service record uri( or the srv string ), that later resolves to all these host names, making client side hassel less.
3. srv string: mongodb+srv://<user>:<password>@<hostname of cluster containing srv record>/<database>
    . if there are huge number of 
ex.: mongodb+srv://Shubham:pyLMjjKKPxsxH3zZ@mflix.zvvo9.mongodb.net/test 

# Querying in mongodb

    find query:
        {key:{$and:['t1','q1','q3']}} 
            // will find element with 'key' having array of all of the elements in array given
        {key:{$in:['t1','q1','q3']}} 
            // will find element with 'key' having array of any of the elements in array given

# cursor methods
    pagination:
        db.find(query).sort({someKey:-1}).skip(20*pageNumber).limit(20).toArray()
        can be done with aggregation as well

# fascet aggregation

# loockup aggregation
    when we need to aggregate documents from other collection with each document in the collection in current pipeline
    example: while reading movies collection, we want to aggregate each movie document with all comments realted with it from comments collection
    syntax type 1: 
    db.orders.aggregate( [
    {
        $lookup:
        {
            from: "inventory",
            localField: "item",
            foreignField: "sku",
            as: "inventory_docs"
        }
    }
    ] )
    explanation: 
        for each document in orders collection that comes to loockup stage, an array of name "inventory_docs" is appended, which consists of all documents in "inventory" collection that have "sku" field equal to "item" field of this object
        and resulting documents are forwarded/returned by pipeline
     
    syntax type 2:

    db.orders.aggregate( [
   {
        $lookup:
            {
            from: "warehouses",
            let: { order_item: "$item", order_qty: "$ordered" },
            pipeline: [
                { $match:
                    { $expr:
                        { $and: [
                            { $eq: [ "$stock_item",  "$$order_item" ] },
                            { $gte: [ "$instock", "$$order_qty" ] }
                            ]
                        }
                    }
                },
                { $project: { stock_item: 0, _id: 0 } }
            ],
            as: "stockdata"
            }
        }
    ] )
    explanation: 
        for each order document in orders collection that comes to loockup stage, an array of name "stockdata" is appended, which consists of all documents that are yealded by passing inn "warehouses" collection in given pipeline.
        this nested pipeline has access to variables of order document defined in "let" stage 
        and resulting documents are forwarded/returned by pipeline

# group aggregation
    
    when needed to find some statastics(max/min/count/sum/avr...) of perticular field in documents passed
    
    ex. pipeline gets comment objects, of type: {user:"sam", text:'blabla', likes: 10}
    then to find total comment objects corrosponding to each user, we group the pipeline by user, and then count each group. as:
    [
        {
          $group: {
            _id: "$user",
            count: { $count: {} },
            likes: {$sum: "$likes" }
          }
        }
      ]
    
    what it does:
    groups all the documents from the given pipeline that match the criteria by _id, and then 
    on each of the groups, evaluates the value of all the fields by once iterating over them using the different accumulator expressions available, i.e. sum, max, min, count...

     
# delete operations
    deleteOne
        delets first matching document
        if multiple documents match, it will delete first matching document in natural order
        natural order: order in which documents were inserted

# replica set
    when need for data consistancy and reliablity on server going down is very important

    primary replica set
        operation log -> secondary replica set -> election -> primary replica set

    wright consern:
        values: 1,2,..n,"majority",0
        used with update, updateOne, ...
        syntax: like upsert, : {w:"majority"}

        wtimeout: how long to wait before getting the response from the server?
        
        there may be grid-lock kind of situation when there is huge wright operations load, as result, the majority condition may never come true, i.e. all servers busy in some other operations ...
        so, a timeout has to be necessary, so that frontend is notified to re-try after some time...
        
        similerly, there is server selection timeout, time needed for driver to select the primary db in process of election(*not sure) , this is time needed for recovery from crash in case of primary server goes down (or any other secondary goes down...), so, if this time exceeds certain limits, we should get notified, in case hardware dimage, etc that needs attention. 

    read consern:
        "local", "majority"
        used with find, findOne, ...
        syntax: like upsert, : {r:"local"}


# connection pooling
    when a client wants to make multiple connections with the db, each time we connect there is cost of time, so mongo driver creates a pool of 100 connections by default when a client joins, so that if there is sudden need of more connections from the client, they are picked up from the pool !
    https://mongodb.github.io/node-mongodb-native/3.5/reference/connecting/connection-settings/ 


# good server design practices
## DAO class for database management
1. we create DAO classes for each data collection like movies/users/comments..., with static methods that contain CRUD and other custom functionality for that perticular collection. 
2. each DAO class has inject/init collection method, which takes inn the db object, and stores collection object i.e. db.movies / db.comments that might be required in the class, as a static vatiable, or as a local variable of that module, from where a class is being exported.
3. each DAO class is initiated when application is starting
4. these DAO classes abstract out actual database implementations, and provide perticular functionalities wherever needed, i.e. in middlewares or controllers...
## server structure for how we handle api requests
4. in index/server.js we init the express and mongoClient, import all routes, connect all paths directly to app with proper routes, or static file directories
5. in in routs we add rout to controller for each sub path, any middleware may be added here
6. in controllers, we import DAO and do the proper data processing and return json
## middlewares
1. for validating the schemas structure and type for the request body/query params
   1. tools used for validation: zod, prisma.
2. for authentication : jwt cookie , csrf token , ...
   1. tools used: jwt, hashing, ...(?)
3. for checknig the privilages/power associated with request (is admin/is paid user...)