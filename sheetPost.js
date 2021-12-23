const data = {
    Id: 10,
    Name: "Jack Doe",
    Age: 97,
    "Created at": new Date(),
  };
  
  // Add one line to the sheet
  fetch("https://sheet.best/api/sheets/65350fd3-7861-48a2-b560-132ec26c1b33", {
    method: "POST",
    mode: "cors",
    headers: {
      "Content-Type": "application/json",
    },
    body: JSON.stringify(data),
  })
    .then((r) => r.json())
    .then((data) => {
      // The response comes here
      console.log(data);
    })
    .catch((error) => {
      // Errors are reported there
      console.log(error);
    });
  
  // Add two lines to the sheet
  fetch("https://sheet.best/api/sheets/65350fd3-7861-48a2-b560-132ec26c1b33", {
    method: "POST",
    mode: "cors",
    headers: {
      "Content-Type": "application/json",
    },
    body: JSON.stringify([
      {
        Id: "10",
        Name: "Jack Doe",
        Age: "97",
        "Created at": datetime.now().isoformat(),
      },
      {
        Id: "11",
        Name: "John Doe",
        Age: "44",
        "Created at": datetime.now().isoformat(),
      },
    ]),
  })
    .then((r) => r.json())
    .then((data) => {
      // The response comes here
      console.log(data);
    })
    .catch((error) => {
      // Errors are reported there
      console.log(error);
    });
  