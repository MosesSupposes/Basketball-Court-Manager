[@react.component]
let make = () => {
  let (teams: list(Team.t), setTeams) =
    React.useState(() =>
      [
        ({name: "Mambas", captain: "Kobe Bryant"}: Team.t),
        {name: "Moses and the Mosets", captain: "Moses Samuel"},
        {name: "The Mini Mikes", captain: "Michael Sadaghyani"},
      ]
    );

  let addNewTeam = (team: Team.t) =>
    setTeams(prevTeams => [team, ...prevTeams]);

  <main>
    <TeamCreator update=addNewTeam />
    <TeamList teams />
    <WaitTime queue=teams />
  </main>;
};
