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

  let (shouldShowWaitTime, setShouldShowWaitTime) =
    React.useState(() => false);

  let addNewTeam = (team: Team.t) =>
    setTeams(prevTeams => [team, ...prevTeams]);

  <main>
    <TeamCreator update=addNewTeam renderWaitTime=setShouldShowWaitTime />
    <TeamList teams />
    <WaitTime queue=teams shouldShowWaitTime />
    <GameOver setTeams />
    <QRCode dataToEncode="MosesSupposes rocks" />
  </main>;
};
