[@bs.module "../services/qrCode.js"] external qrCode: Js.t('a) = "default";

type dataOptions('a) =
  Js.t(
    {
      ..
      "color": string,
      "type_": string,
    } as 'a,
  );

type backgroundOptions('a) = Js.t({.. color: string} as 'a);

type imageOptions('a) =
  Js.t(
    {
      ..
      crossOrigin: string,
      margin: string,
    } as 'a,
  );

[@react.component]
let make =
    (
      ~dataToEncode: string,
      ~imgToEncode: option(string)=?,
      ~width: option(int)=?,
      ~height: option(int)=?,
      ~dataOptions: option(dataOptions('a))=?,
      ~backgroundOptions: option(backgroundOptions('b))=?,
      ~imageOptions: option(imageOptions('c))=?,
    ) => {
  let newlyGeneratedQRCode =
    qrCode##genQRCode({
      "data": dataToEncode,
      "image": imgToEncode,
      "dataOptions": dataOptions,
      "backgroundOptions": backgroundOptions,
      "imageOptions": imageOptions,
    });

  let canvas = <canvas id="qrCode" />;

  qrCode##renderQRCode(newlyGeneratedQRCode, canvas);
};
