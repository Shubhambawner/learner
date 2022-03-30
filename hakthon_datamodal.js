//* session

//Category (here we call it tag, as problems will be asorted on basis of them)
var tag = {

}


//TOPIC
var project = {
    //1 project identifier data
    _id: "", // MongoDB object ID
    _key:"topic:38",
    tid: 38, //tipoc id of project, or project id (should we name it as pids?)
    uid: 111, //user id of recruiter
    // cid: "", // this topic is not linked with one catagory, but many
    cids: [  //* array of categories objects with minor detail st we dont need to call {db id type name
        {
            cid:2,
            name:"JS",
            link: '',//? should we have it?
        } //category , and array of subcategories associated with it inside
    ], // array of of categories (just like TAGs, a project can have multiple tags) (should we name it as tags?)
    type: 'project',
        
    //2 Project specific data: that recruiter will set
    title: "", // project name
    short_description: "", // project description
    description: "", // project description
    start_time: "", // project start date
    end_time: [], // array of project end dates from which applicants can select one
    status:'',//,draft, published, closed
    uploadedpictures: [
        {name: "", url: "", description: ""},
    ], // uploaded picture of project
        //recruiter_uid: 420, // uid of recruiter

    //3 Recruiter specific data:
    recruiter: {
        uid: "", // user id of recruiter
        username: "", // user name of recruiter
        fullname:'',
        userslug: '',
        picture:'',
        aboutme: "", // description of recruiter
        status: "", // status of recruiter, online offline
    }, // project recruiter
    // tasks: [999, 907], // array of task ids //! is it needed? we can use for(i in task_data){} loop or Object.keys(task_data)
    
    //3 applicants and their data:
    task_data: [999, 990], // array of Object ids of tasks    
}

// to update data in database see https://www.mongodb.com/docs/manual/reference/command/findAndModify/#examples
// to directly get count of documents see 

//an asset class just like feedbacks we have in the database
//
var task = {
    pid: 999, // unique id
    _key: "task:999",
    tid:38,
    uid:111,
    
    attachment_type:'project',
    type: 'task',
    
    deadline: (project_end_time), // project end date 
    asignment_resources: { 
        thread_builder:true,
        link:false,
        file:false,
        text:true
    }
}

//POST to the TOPIC
var submissionInfo = {
    _key: "post:453", // MongoDB object ID
    pid:453,
    tid: 38, // task id

    uid: 1, // user id of  applicant (mongodb wala ?)
    name:'', // user name
    
    attachment_id:38,
    attachment_type:'project',
    
    status:'',// submitted, pending, reasigned, accepted.
    latest_subtask_submit_time: "", // latest submission time.
    
    selected_submit_time: "", // selected submission time
    data: [   
        {
            task_id: 999, // task id
            submission:{
                link:'',
                text:'',
                file:null,
                thread_builder_id:344,
                image:null
            }, // task data
            sharer:{
                // sharer object 
            },
            
            submit_time: Date.now(), // submit time, when user submits this sub task
            status:'',// submitted, pending, reasigned, accepted.
        }
    ]    

}

// var response = {
//     response_id: 34, // unique response id
//     type: 'response',
//     task_id: 999, // task id it is attached to
//     user_uid: 1, // user id it is attached to
//     submit_time: 1241241243, // submit time, will be NULL till he submits the task(or marks task as done)
// }

/**
  //! Discarded:
 * get project for user: 
 * first we query the database for : {"type":"project", applicants:96} (where 96 is user id of user who is logged in)
 * then we iterate over each session as:
 *      modify task data to contain data of task made by him only
 *      to achive this we do: iterate over each task_id in tasks array:
 *          task_data[task_id] = response object of response id = task_data[task_id][96]
 */

  /**
   * //* Recruiter side:
   * 1.  when goes to project:
   * - make get project call
   * 1.1 goes to body of project:
   * - make get task call via pagination  
   */