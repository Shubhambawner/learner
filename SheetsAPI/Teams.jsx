import { useEffect, useState } from "react";

//api
import axios from "axios";

//css
import "../assets/stylesheets/Teams.css";

const Teams = () => {
  const [TeamData, setTeamData] = useState(null);
  const [loaded, setLoaded] = useState(false);
  useEffect(() => {
    axios
      .get(
        "https://sheets.googleapis.com/v4/spreadsheets/1ZP3Q05AMXjBLXmTKVEUwF05XoEbE4Hi7SN7MOGALMu0/values/Sheet1?key=621d68fa9166477130b8672f195ce205242d70bd"
      )
      .then((res) => {
        console.log(res.data.values);
        setTeamData(res.data.values);
        setLoaded(true);
      })
      .catch((err) => console.log(err));
  }, []);

  const renderTeam = () => {
    if (TeamData === null) {
      return;
    }
    const Team = TeamData.map((member, i) => {
      if (i === 0) return "";
      return (
        <div className="col-md-3" key={i}>
          <div className="team_card">
            <div className="team_img_wrap_outer">
              <div className="team_img_wrap">
                <a target="_blank" href={member[5]} rel="noreferrer">
                  <div className="team_social team_linkedin">
                    <i className="fa fa-linkedin"></i>
                  </div>
                </a>
                <a target="_blank" href={member[4]} rel="noreferrer">
                  <div className="team_social team_insta">
                    <i className="fa fa-instagram"></i>
                  </div>
                </a>
                <a target="_blank" href={member[6]} rel="noreferrer">
                  <div className="team_social team_email">
                    <i className="fa fa-envelope"></i>
                  </div>
                </a>
                <img
                  className="team_img"
                  src={`https://gdurl.com${member[3]}`}
                  alt="."
                />
              </div>
            </div>
            <div className="team_name">{member[1]}</div>
            <div className="team_desigination">{member[2]}</div>
          </div>
        </div>
        // <div className="col-md-3" key={i}>
        //   <div className="single-team">
        //     <div className="team-img">
        //       <img src={`https://gdurl.com${member[3]}`} alt="" />
        //     </div>
        //     <div className="team-content">
        //       <div className="team-info">
        //         <h3>{member[1]}</h3>
        //         <p>{member[2]}</p>
        //       </div>
        //       <p className="team-icon">
        //         <a target="_blank" href={member[4]} rel="noreferrer">
        //           <i className="fa fa-instagram" aria-hidden="true"></i>
        //         </a>
        //         <a target="_blank" href={member[5]} rel="noreferrer">
        //           <i className="fa fa-linkedin" aria-hidden="true"></i>
        //         </a>
        //         <a target="_blank" href={member[6]} rel="noreferrer">
        //           <i className="fa fa-envelope-o" aria-hidden="true"></i>
        //         </a>
        //       </p>
        //     </div>
        //   </div>
        // </div>
      );
    });
    return Team;
  };

  return (
    <>
      <div className="team-area" id="team">
        <div className="container team_wrap blob">
          <div className="team-heading">
            <h1>Team Members</h1>
            <p>Meet Our Talented Team Member</p>
          </div>
          <div className="row" style={{ padding: "5%" }}>
            {loaded ? renderTeam() : "Loading..."}
          </div>
        </div>
      </div>
    </>
  );
};

export default Teams;
